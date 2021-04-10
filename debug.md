# solved and unsolved bugs

很多都直接写在注释里面了

1. 内核空间和用户空间不能互相访问

kernel output
```
Unable to handle kernel NULL pointer dereference at virtual address 00000800
...
Internal error: Oops: 5 [#1] PREEMPT ARM
...
Kernel panic - not syncing: Fatal exception
```

2. 内核不断调用system call(unsolved)

kernel output
```
entry secceed!
copy failed!
init: Service 'zygote' (pid 2194) killed by signal 9
init: Service 'zygote' (pid 2194) killing any children in process group
init: write_file: Unable to open '/sys/android_power/request_state': No such file or directory
init: write_file: Unable to write to '/sys/power/state': Invalid argument
init: Service 'media' is being killed...
init: Service 'netd' is being killed...
init: Service 'netd' (pid 2192) killed by signal 9
init: Service 'netd' (pid 2192) killing any children in process group
init: Service 'media' (pid 2193) killed by signal 9
init: Service 'media' (pid 2193) killing any children in process group
init: Starting service 'netd'...
init: Starting service 'media'...
init: Starting service 'zygote'...
init: Untracked pid 2315 killed by signal 9
```
不断循环

3. 输出的缩进不对

把dfs递归调用的最后一个参数，`++generation`改为了`generation+1`

