This is a test for project 1:

memory allocation secceed!
system call secceed!
swapper,0,0,-1,1,-1,0
	init,1,1,0,45,2,0
		ueventd,45,1,1,-1,62,0
		logd,62,1,1,-1,63,1036
		vold,63,1,1,-1,67,0
		healthd,67,1,1,-1,68,0
		lmkd,68,1,1,-1,69,0
		servicemanager,69,1,1,-1,70,1000
		surfaceflinger,70,1,1,-1,72,1000
		qemud,72,1,1,-1,75,0
		sh,75,1,1,-1,76,2000
		adbd,76,1,1,183,77,0
			sh,183,1,76,225,-1,0
				mainARM,225,0,183,-1,-1,0
		netd,77,1,1,224,78,0
			iptables,224,0,77,-1,-1,0
		debuggerd,78,1,1,-1,79,0
		rild,79,1,1,-1,80,1001
		drmserver,80,1,1,-1,81,1019
		mediaserver,81,1,1,-1,82,1013
		installd,82,1,1,-1,83,0
		keystore,83,1,1,-1,84,1017
		main,84,2,1,-1,85,0
		gatekeeperd,85,1,1,-1,86,1000
		perfprofd,86,1,1,-1,87,0
		fingerprintd,87,1,1,-1,119,1000
		bootanimation,119,1,1,-1,-1,1003
	kthreadd,2,1,0,3,-1,0
		ksoftirqd/0,3,1,2,-1,4,0
		kworker/0:0,4,1,2,-1,5,0
		kworker/u:0,5,1,2,-1,6,0
		khelper,6,1,2,-1,7,0
		sync_supers,7,1,2,-1,8,0
		bdi-default,8,1,2,-1,9,0
		kblockd,9,1,2,-1,10,0
		rpciod,10,1,2,-1,11,0
		kworker/0:1,11,1,2,-1,12,0
		kswapd0,12,1,2,-1,13,0
		fsnotify_mark,13,1,2,-1,14,0
		crypto,14,1,2,-1,25,0
		kworker/u:1,25,1,2,-1,30,0
		mtdblock0,30,1,2,-1,35,0
		mtdblock1,35,1,2,-1,40,0
		mtdblock2,40,1,2,-1,41,0
		binder,41,1,2,-1,42,0
		deferwq,42,1,2,-1,43,0
		kworker/u:2,43,1,2,-1,44,0
		mmcqd/0,44,1,2,-1,47,0
		jbd2/mtdblock0-,47,1,2,-1,48,0
		ext4-dio-unwrit,48,1,2,-1,51,0
		flush-31:1,51,1,2,-1,53,0
		kworker/0:2,53,1,2,-1,54,0
		jbd2/mtdblock1-,54,1,2,-1,55,0
		ext4-dio-unwrit,55,1,2,-1,58,0
		flush-31:2,58,1,2,-1,60,0
		jbd2/mtdblock2-,60,1,2,-1,61,0
		ext4-dio-unwrit,61,1,2,-1,101,0
		kauditd,101,1,2,-1,-1,0
Test End!