# オペレーティングシステム


### 3 Approaches to virtualize an unvirtualizable CPU

1. binary translation (VM Ware)
    - literally boot the system
2. paravirtualizationi (Xen)
    - Xen is a hyporvisor
    - they modify the kernel code; OS cooperates with hyporvisor. Looks like a system call, but actually its a hyporvisor call.
3. 



