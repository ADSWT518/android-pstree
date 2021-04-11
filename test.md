# test input and output

## problem 1

```
root@generic:/data/misc/cs356 # insmod ptree.ko                                
root@generic:/data/misc/cs356 # lsmod
Module                  Size  Used by
ptree                   1557  0 
```

## problem 2

```
root@generic:/data/misc/cs356 # ./testARM                                      
This is a test for project 1, ptree system call:

init,1,1,0,45,2,0
	ueventd,45,1,1,0,61,0
	logd,61,1,1,0,62,1036
	vold,62,1,1,0,66,0
	healthd,66,1,1,0,67,0
	lmkd,67,1,1,0,68,0
	servicemanager,68,1,1,0,69,1000
	surfaceflinger,69,1,1,0,71,1000
	qemud,71,1,1,0,74,0
	sh,74,1,1,0,75,2000
	adbd,75,1,1,1029,76,0
		sh,1029,1,75,1150,0,0
			testARM,1150,0,1029,0,0,0
	netd,76,1,1,0,77,0
	debuggerd,77,1,1,0,78,0
	rild,78,1,1,0,79,1001
	drmserver,79,1,1,0,80,1019
	mediaserver,80,1,1,0,81,1013
	installd,81,1,1,0,82,0
	keystore,82,1,1,0,83,1017
	main,83,1,1,230,84,0
		system_server,230,1,83,0,663,1000
		putmethod.latin,663,1,83,0,680,10032
		m.android.phone,680,1,83,0,688,1001
		droid.launcher3,688,1,83,0,715,10007
		d.process.acore,715,1,83,0,747,10002
		d.process.media,747,1,83,0,812,10005
		ndroid.systemui,812,1,83,0,834,10013
		droid.deskclock,834,1,83,0,906,10023
		.quicksearchbox,906,1,83,0,951,10042
		ndroid.settings,951,1,83,0,965,1000
		ndroid.calendar,965,1,83,0,991,10019
		viders.calendar,991,1,83,0,1079,10001
		m.android.email,1079,1,83,0,1094,10027
		ndroid.exchange,1094,1,83,0,0,10029
	gatekeeperd,84,1,1,0,85,1000
	perfprofd,85,1,1,0,86,0
	fingerprintd,86,1,1,0,0,1000
kthreadd,2,1,0,3,0,0
	ksoftirqd/0,3,1,2,0,4,0
	kworker/0:0,4,1,2,0,6,0
	khelper,6,1,2,0,7,0
	sync_supers,7,1,2,0,8,0
	bdi-default,8,1,2,0,9,0
	kblockd,9,1,2,0,10,0
	rpciod,10,1,2,0,12,0
	kswapd0,12,1,2,0,13,0
	fsnotify_mark,13,1,2,0,14,0
	crypto,14,1,2,0,25,0
	kworker/u:1,25,1,2,0,30,0
	mtdblock0,30,1,2,0,35,0
	mtdblock1,35,1,2,0,40,0
	mtdblock2,40,1,2,0,41,0
	binder,41,1,2,0,42,0
	deferwq,42,1,2,0,43,0
	kworker/u:2,43,1,2,0,44,0
	mmcqd/0,44,1,2,0,47,0
	jbd2/mtdblock0-,47,1,2,0,48,0
	ext4-dio-unwrit,48,1,2,0,53,0
	jbd2/mtdblock1-,53,1,2,0,54,0
	ext4-dio-unwrit,54,1,2,0,59,0
	jbd2/mtdblock2-,59,1,2,0,60,0
	ext4-dio-unwrit,60,1,2,0,102,0
	kauditd,102,1,2,0,1114,0
	kworker/0:1,1114,1,2,0,1130,0
	flush-31:1,1130,1,2,0,0,0
Test End!
```

## problem 3

```
root@generic:/data/misc/cs356 # ./forkARM                                      
This is a test for project 1, fork and execute the test of ptree:

519021910804 child pid: 1152
This is a test for project 1, ptree system call:

init,1,1,0,45,2,0
	ueventd,45,1,1,0,61,0
	logd,61,1,1,0,62,1036
	vold,62,1,1,0,66,0
	healthd,66,1,1,0,67,0
	lmkd,67,1,1,0,68,0
	servicemanager,68,1,1,0,69,1000
	surfaceflinger,69,1,1,0,71,1000
	qemud,71,1,1,0,74,0
	sh,74,1,1,0,75,2000
	adbd,75,1,1,1029,76,0
		sh,1029,1,75,1151,0,0
			forkARM,1151,1,1029,1152,0,0
				testARM,1152,0,1151,0,0,0
	netd,76,1,1,0,77,0
	debuggerd,77,1,1,0,78,0
	rild,78,1,1,0,79,1001
	drmserver,79,1,1,0,80,1019
	mediaserver,80,1,1,0,81,1013
	installd,81,1,1,0,82,0
	keystore,82,1,1,0,83,1017
	main,83,1,1,230,84,0
		system_server,230,1,83,0,663,1000
		putmethod.latin,663,1,83,0,680,10032
		m.android.phone,680,1,83,0,688,1001
		droid.launcher3,688,1,83,0,715,10007
		d.process.acore,715,1,83,0,747,10002
		d.process.media,747,1,83,0,812,10005
		ndroid.systemui,812,1,83,0,834,10013
		droid.deskclock,834,1,83,0,906,10023
		.quicksearchbox,906,1,83,0,951,10042
		ndroid.settings,951,1,83,0,965,1000
		ndroid.calendar,965,1,83,0,991,10019
		viders.calendar,991,1,83,0,1079,10001
		m.android.email,1079,1,83,0,1094,10027
		ndroid.exchange,1094,1,83,0,0,10029
	gatekeeperd,84,1,1,0,85,1000
	perfprofd,85,1,1,0,86,0
	fingerprintd,86,1,1,0,0,1000
kthreadd,2,1,0,3,0,0
	ksoftirqd/0,3,1,2,0,4,0
	kworker/0:0,4,1,2,0,6,0
	khelper,6,1,2,0,7,0
	sync_supers,7,1,2,0,8,0
	bdi-default,8,1,2,0,9,0
	kblockd,9,1,2,0,10,0
	rpciod,10,1,2,0,12,0
	kswapd0,12,1,2,0,13,0
	fsnotify_mark,13,1,2,0,14,0
	crypto,14,1,2,0,25,0
	kworker/u:1,25,1,2,0,30,0
	mtdblock0,30,1,2,0,35,0
	mtdblock1,35,1,2,0,40,0
	mtdblock2,40,1,2,0,41,0
	binder,41,1,2,0,42,0
	deferwq,42,1,2,0,43,0
	kworker/u:2,43,1,2,0,44,0
	mmcqd/0,44,1,2,0,47,0
	jbd2/mtdblock0-,47,1,2,0,48,0
	ext4-dio-unwrit,48,1,2,0,53,0
	jbd2/mtdblock1-,53,1,2,0,54,0
	ext4-dio-unwrit,54,1,2,0,59,0
	jbd2/mtdblock2-,59,1,2,0,60,0
	ext4-dio-unwrit,60,1,2,0,102,0
	kauditd,102,1,2,0,1114,0
	kworker/0:1,1114,1,2,0,1130,0
	flush-31:1,1130,1,2,0,0,0
Test End!

519021910804 parent pid: 1151
```

## problem 4

```
root@generic:/data/misc/cs356 # ./BBC
wrong argument input!
1|root@generic:/data/misc/cs356 # ./BBC 0 1 41 10                              
There must be at least 1 cook and 1 cashier!
1|root@generic:/data/misc/cs356 # ./BBC 2 6 41 0                               
The size of rack must be at least 1.
1|root@generic:/data/misc/cs356 # ./BBC 2 6 0 10                               
There must be at least 1 customer!
1|root@generic:/data/misc/cs356 # ./BBC 2 6 41 10                              
Cooks [2], Cashiers [6], Customers [41]
Begin run.
Customer [15] come.
Customer [9] come.
Cashier [6] accepts an order.
Cashier [5] accepts an order.
Customer [7] come.
Cashier [4] accepts an order.
Customer [26] come.
Cashier [3] accepts an order.
Cook [2] make a burger.
Cook [1] make a burger.
Cashier [6] takes a burger to cunstomer.
Cashier [5] takes a burger to cunstomer.
Customer [6] come.
Customer [12] come.
Cashier [2] accepts an order.
Cashier [1] accepts an order.
Cook [2] make a burger.
Cook [1] make a burger.
Cashier [4] takes a burger to cunstomer.
Cashier [3] takes a burger to cunstomer.
Customer [25] come.
Customer [37] come.
Cashier [6] accepts an order.
Cashier [5] accepts an order.
Customer [24] come.
Cashier [4] accepts an order.
Cook [2] make a burger.
Cashier [2] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [1] takes a burger to cunstomer.
Customer [19] come.
Cashier [3] accepts an order.
Customer [33] come.
Cashier [2] accepts an order.
Cook [2] make a burger.
Cashier [6] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [5] takes a burger to cunstomer.
Customer [34] come.
Cashier [1] accepts an order.
Customer [13] come.
Cashier [6] accepts an order.
Cook [2] make a burger.
Cashier [4] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [3] takes a burger to cunstomer.
Customer [8] come.
Cashier [5] accepts an order.
Cook [2] make a burger.
Cashier [2] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [1] takes a burger to cunstomer.
Customer [29] come.
Cashier [4] accepts an order.
Cook [2] make a burger.
Cashier [6] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [5] takes a burger to cunstomer.
Customer [31] come.
Cashier [3] accepts an order.
Customer [39] come.
Cashier [2] accepts an order.
Cook [2] make a burger.
Cashier [4] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [3] takes a burger to cunstomer.
Customer [35] come.
Customer [16] come.
Customer [21] come.
Cashier [1] accepts an order.
Cashier [6] accepts an order.
Cashier [5] accepts an order.
Cook [2] make a burger.
Cashier [2] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [1] takes a burger to cunstomer.
Customer [11] come.
Cashier [4] accepts an order.
Customer [4] come.
Cashier [3] accepts an order.
Cook [2] make a burger.
Cashier [6] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [5] takes a burger to cunstomer.
Customer [10] come.
Cashier [2] accepts an order.
Customer [2] come.
Cashier [1] accepts an order.
Cook [2] make a burger.
Cashier [4] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [3] takes a burger to cunstomer.
Customer [5] come.
Cashier [6] accepts an order.
Cook [2] make a burger.
Cashier [2] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [1] takes a burger to cunstomer.
Customer [36] come.
Cashier [5] accepts an order.
Customer [30] come.
Cashier [4] accepts an order.
Customer [22] come.
Cashier [3] accepts an order.
Cook [2] make a burger.
Cashier [6] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [5] takes a burger to cunstomer.
Customer [18] come.
Customer [27] come.
Cashier [2] accepts an order.
Cashier [1] accepts an order.
Customer [17] come.
Customer [32] come.
Cashier [6] accepts an order.
Cashier [5] accepts an order.
Cook [2] make a burger.
Cashier [4] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [3] takes a burger to cunstomer.
Cook [2] make a burger.
Cashier [2] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [1] takes a burger to cunstomer.
Customer [28] come.
Cashier [4] accepts an order.
Customer [1] come.
Cashier [3] accepts an order.
Cook [2] make a burger.
Cashier [6] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [5] takes a burger to cunstomer.
Customer [38] come.
Cashier [2] accepts an order.
Customer [14] come.
Cashier [1] accepts an order.
Customer [40] come.
Customer [41] come.
Customer [3] come.
Cashier [6] accepts an order.
Cashier [5] accepts an order.
Cook [2] make a burger.
Cashier [4] takes a burger to cunstomer.
Cashier [4] accepts an order.
Cook [1] make a burger.
Cashier [3] takes a burger to cunstomer.
Customer [20] come.
Cashier [3] accepts an order.
Customer [23] come.
Cook [2] make a burger.
Cashier [2] takes a burger to cunstomer.
Cashier [2] accepts an order.
Cook [1] make a burger.
Cashier [1] takes a burger to cunstomer.
Cook [2] make a burger.
Cashier [6] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [5] takes a burger to cunstomer.
Cook [2] make a burger.
Cashier [4] takes a burger to cunstomer.
Cook [1] make a burger.
Cashier [3] takes a burger to cunstomer.
Cook [2] make a burger.
Cashier [2] takes a burger to cunstomer.
End run.
```