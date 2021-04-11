/*****************************************************************************
File name: BurgerBuddies.c
Description: 
    This file implements a simulation of process scheduling. It will get 4 
    input, the number of cooks, cashiers, customers, and the size of the rack.
    and it will simulate the situation of a burger restaurant.
Author: ADSWT518
Version: 1.0
Date: 2021.4.10
Fucntion list:
1. void *cook(void *cookId)
    Funtion of the cook thread.
2. void *cashier(void *cashierId)
    Function of the cashier thread.
3. void *customer(void *customerId)
    Function of the customer thread.
4. void *killer()
    Function of the killer thread, used to end the cook thread and cashier thread.
5. void thread_exit_handler()
    This function will be called when the cook thread and cashier thread receive
    a signal SIGQUIT, and finish the thread.
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <signal.h>

// 用到了pthread库，所以在编译时注意加上-lpthread参数，以调用静态链接库

sem_t rack_empty, rack_full, order, cashier_ready, burger_ready, can_kill;
pthread_mutex_t burger_mutex, customer_mutex;
int burger_count = 0;    // 做好的汉堡个数
int customer_remain = 0; // 还没有到来的消费者人数

void *cook(void *cookId);
void *cashier(void *cashierId);
void *customer(void *customerId);
void *killer();
void thread_exit_handler();

pthread_t *cook_threads, *cashier_threads, *customer_threads, killer_thread;
int cookNum, cashierNum, customerNum, rackSize;

int main(int argc, char **argv)
{
    srand((unsigned)time(NULL));

    if (argc != 5)
    {
        printf("wrong argument input!\n");
        exit(1);
    }

    cookNum = atoi(argv[1]);
    cashierNum = atoi(argv[2]);
    customerNum = atoi(argv[3]);
    rackSize = atoi(argv[4]);
    customer_remain = customerNum;

    if (cookNum < 1 || cashierNum < 1)
    {
        printf("There must be at least 1 cook and 1 cashier!\n");
        exit(1);
    }

    if (rackSize < 1)
    {
        printf("The size of rack must be at least 1.\n");
        exit(1);
    }

    if (customerNum < 1)
    {
        printf("There must be at least 1 customer!\n");
        exit(1);
    }

    printf("Cooks [%d], Cashiers [%d], Customers [%d]\n", cookNum, cashierNum, customerNum);
    printf("Begin run.\n");

    cook_threads = (pthread_t *)malloc(sizeof(pthread_t) * cookNum);
    cashier_threads = (pthread_t *)malloc(sizeof(pthread_t) * cashierNum);
    customer_threads = (pthread_t *)malloc(sizeof(pthread_t) * customerNum);
    pthread_t killer_threads;

    pthread_mutex_init(&burger_mutex, NULL);
    pthread_mutex_init(&customer_mutex, NULL);
    sem_init(&rack_empty, 0, rackSize);
    sem_init(&rack_full, 0, 0);
    sem_init(&order, 0, 0);
    sem_init(&cashier_ready, 0, cashierNum);
    sem_init(&burger_ready, 0, 0);
    sem_init(&can_kill, 0, 0);

    // printf("Initialization succeed!\n");

    int i;
    // 创建线程
    for (i = 0; i < cookNum; ++i)
    {
        if (pthread_create(cook_threads + i, NULL, cook, (void *)i))
        {
            printf("cook thread create failed\n");
        }
    }
    for (i = 0; i < cashierNum; ++i)
    {
        if (pthread_create(cashier_threads + i, NULL, cashier, (void *)i))
        {
            printf("cashier thread create failed\n");
        }
    }
    for (i = 0; i < customerNum; ++i)
    {
        if (pthread_create(customer_threads + i, NULL, customer, (void *)i))
        {
            printf("customer thread create failed\n");
        }
    }

    pthread_create(&killer_thread, NULL, killer, NULL);

    // printf("Threads creation succeed!\n");

    // 等待线程结束

    if (pthread_join(killer_thread, NULL))
    {
        printf("wait killer thread failed\n");
    }

    for (i = 0; i < cookNum; ++i)
    {
        if (pthread_join(*(cook_threads + i), NULL))
        {
            printf("wait cook thread failed\n");
        }
    }
    // printf("cook join!\n");
    for (i = 0; i < cashierNum; ++i)
    {
        if (pthread_join(*(cashier_threads + i), NULL))
        {
            printf("wait cashier thread failed\n");
        }
    }
    // printf("cashier join!\n");
    for (i = 0; i < customerNum; ++i)
    {
        if (pthread_join(*(customer_threads + i), NULL))
        {
            printf("wait customer thread failed\n");
        }
    }

    // printf("Threads join succeed!\n");

    sem_destroy(&rack_full);
    sem_destroy(&rack_empty);
    sem_destroy(&order);
    sem_destroy(&cashier_ready);
    sem_destroy(&burger_ready);
    pthread_mutex_destroy(&burger_mutex);
    pthread_mutex_destroy(&customer_mutex);

    free(cook_threads);
    free(cashier_threads);
    free(customer_threads);

    printf("End run.\n\n");

    return 0;
}

void *cook(void *cookId)
{
    signal(SIGQUIT, thread_exit_handler);
    while (1)
    {
        // printf("cook: **customer_remain is %d**\n", customer_remain);

        sleep(1); // 厨师做汉堡也需要时间！
        sem_wait(&rack_empty);
        pthread_mutex_lock(&burger_mutex);
        printf("Cook [%d] make a burger.\n", (int)cookId + 1);
        ++burger_count;
        // printf("(current burger_count is %d)\n", burger_count);
        pthread_mutex_unlock(&burger_mutex);
        sem_post(&rack_full);
    }
    // printf("cook over!!!\n");
}

void *cashier(void *cashierId)
{
    signal(SIGQUIT, thread_exit_handler);
    while (1)
    {
        // printf("cashier: **customer_remain is %d**\n", customer_remain);

        sem_wait(&order);
        printf("Cashier [%d] accepts an order.\n", (int)cashierId + 1);
        sem_wait(&rack_full);
        pthread_mutex_lock(&burger_mutex);
        printf("Cashier [%d] takes a burger to cunstomer.\n", (int)cashierId + 1);
        --burger_count;
        // printf("(current burger_count is %d)\n", burger_count);
        pthread_mutex_unlock(&burger_mutex);
        sem_post(&rack_empty);
        sem_post(&cashier_ready);
        sem_post(&burger_ready);
    }
    // printf("cashier over!!!\n");
}

void *customer(void *customerId)
{
    sleep(rand() % 20); // 顾客的到来当然也有随机的间隔！
    printf("Customer [%d] come.\n", (int)customerId + 1);

    sem_wait(&cashier_ready);
    sem_post(&order);
    sem_wait(&burger_ready);

    pthread_mutex_lock(&customer_mutex);
    --customer_remain;
    if (customer_remain == 0)
    {
        sem_post(&can_kill);
    }
    pthread_mutex_unlock(&customer_mutex);

    // printf("customer: **customer_remain is %d**\n", customer_remain);

    // printf("------------------------\n");
}

void *killer()
{
    // 安卓中没有pthread_cancel，只能用pthread_kill通过传递信号，并且调用pthread_exit来结束子进程
    // Reference: https://stackoverflow.com/questions/4610086
    // printf("kill start\n");
    sem_wait(&can_kill);
    // printf("kill start\n");
    int i;
    for (i = 0; i < cookNum; ++i)
    {
        pthread_kill(*(cook_threads + i), SIGQUIT);
    }

    for (i = 0; i < cashierNum; ++i)
    {
        pthread_kill(*(cashier_threads + i), SIGQUIT);
    }
    // printf("Threads killed!!!\n");
}

void thread_exit_handler()
{
    pthread_exit(0);
}

// sample input: ./BBC 2 4 41 10