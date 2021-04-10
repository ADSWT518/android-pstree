# output

## problem 1 and 2

This is a test for project 1:

memory allocation secceed!
system call secceed!
init,1,1,0,45,2,0
	ueventd,45,1,1,0,62,0
	logd,62,1,1,0,63,1036
	vold,63,1,1,0,67,0
	healthd,67,1,1,0,68,0
	lmkd,68,1,1,0,69,0
	servicemanager,69,1,1,0,70,1000
	surfaceflinger,70,1,1,0,72,1000
	qemud,72,1,1,0,77,0
	sh,77,1,1,0,78,2000
	adbd,78,1,1,225,80,0
		sh,225,1,78,484,0,0
			mainARM,484,0,225,0,0,0
	debuggerd,80,1,1,0,81,0
	rild,81,1,1,0,82,1001
	drmserver,82,1,1,0,84,1019
	installd,84,1,1,0,85,0
	keystore,85,1,1,0,87,1017
	gatekeeperd,87,1,1,0,88,1000
	perfprofd,88,1,1,0,89,0
	fingerprintd,89,1,1,0,116,1000
	bootanimation,116,1,1,0,439,1003
	main,439,0,1,0,440,0
	netd,440,1,1,485,441,0
		iptables,485,0,440,0,0,0
	mediaserver,441,1,1,0,0,1013
kthreadd,2,1,0,3,0,0
	ksoftirqd/0,3,1,2,0,4,0
	kworker/0:0,4,1,2,0,5,0
	kworker/u:0,5,1,2,0,6,0
	khelper,6,1,2,0,7,0
	sync_supers,7,1,2,0,8,0
	bdi-default,8,1,2,0,9,0
	kblockd,9,1,2,0,10,0
	rpciod,10,1,2,0,11,0
	kworker/0:1,11,1,2,0,12,0
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
	kworker/0:2,47,1,2,0,48,0
	jbd2/mtdblock0-,48,1,2,0,49,0
	ext4-dio-unwrit,49,1,2,0,52,0
	flush-31:1,52,1,2,0,54,0
	jbd2/mtdblock1-,54,1,2,0,55,0
	ext4-dio-unwrit,55,1,2,0,58,0
	flush-31:2,58,1,2,0,60,0
	jbd2/mtdblock2-,60,1,2,0,61,0
	ext4-dio-unwrit,61,1,2,0,118,0
	kauditd,118,1,2,0,0,0
Test End!

## problem 3

This is a test of fork for project 1:

519021910804 child pid: 383
This is a test for project 1:

memory allocation secceed!
system call secceed!
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
	adbd,75,1,1,219,77,0
		sh,219,1,75,381,0,0
			forkARM,381,1,219,383,0,0
				mainARM,383,0,381,0,0,0
	debuggerd,77,1,1,0,78,0
	rild,78,1,1,0,79,1001
	drmserver,79,1,1,0,84,1019
	installd,84,1,1,0,85,0
	keystore,85,1,1,0,87,1017
	gatekeeperd,87,1,1,0,88,1000
	perfprofd,88,1,1,0,89,0
	fingerprintd,89,1,1,0,116,1000
	bootanimation,116,1,1,0,333,1003
	mediaserver,333,1,1,0,334,1013
	main,334,0,1,0,335,0
	netd,335,1,1,384,0,0
		ip6tables,384,0,335,0,0,0
kthreadd,2,1,0,3,0,0
	ksoftirqd/0,3,1,2,0,4,0
	kworker/0:0,4,1,2,0,5,0
	kworker/u:0,5,1,2,0,6,0
	khelper,6,1,2,0,7,0
	sync_supers,7,1,2,0,8,0
	bdi-default,8,1,2,0,9,0
	kblockd,9,1,2,0,10,0
	rpciod,10,1,2,0,11,0
	kworker/0:1,11,1,2,0,12,0
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
	ext4-dio-unwrit,48,1,2,0,51,0
	flush-31:1,51,1,2,0,53,0
	jbd2/mtdblock1-,53,1,2,0,54,0
	ext4-dio-unwrit,54,1,2,0,57,0
	flush-31:2,57,1,2,0,59,0
	jbd2/mtdblock2-,59,1,2,0,60,0
	ext4-dio-unwrit,60,1,2,0,94,0
	kauditd,94,1,2,0,178,0
	kworker/0:2,178,1,2,0,0,0
Test End!

519021910804 parent pid: 381

