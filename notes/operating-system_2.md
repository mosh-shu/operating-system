# オペレーティングシステム

### 20190411

## Kernel and Processes

- program... set of instructions
- process... a running instance of a program, needs resources
- resources: memory, CPU, energy, I/O devices
- process: abstraction of a machine
	- memory: linear array of bits with adresses
	- CPU: if an abstraction of macihne is process, abstraction of CPU is threads
	- storage, I/O: abstraction of file system
	- combined together, if gives us process

## Scheduling

- Waiting time = t_begin - t_arrival
    - amount of workload done since arrival
- Optimization... set every waiting time to an equal value
    - this is "fairness"
    - we can calculate this fairness
    - raj jain's fairness... maximum of 1 when all waiting time is equal
- time to completion for {1, 3, 5}... poor fairness, but good avg. waiting time
- so what is our optimal 目的関数?
    - throughput... jobs per hour
    - fairness
    - responsiveness... not getting that spinning beachball on mac
    - effective utlization of all resources... everyone has different capabilities
- process... instance of a running program; abstraction of a machine
- OS that supports more than one process is multiprogramming / multitasking OS
- if a job is waiting to be processed, context swtich happens (changes the running process)

## Limited Direction Execution Protocol

- Problem: what if there is a need to handle a restricted operation
- Solution: use both User Mode and Kernel Mode
- OS @ boot mode (kernel mode)... initialize trap table, while...
- Hardware remembers te address of a system call handler
- Limit the functinality on the user mode, such as directly modifying memory maps on controling I/O system
- two types of multitasking OS
    - cooperative... "I am willing to give up my CPU resource for others" -> "If not, then I will" forever; if gets stuck in an infinete loop, it had to be rebooted
    - preemptive... "If you don't need it, I'll take it away"... if an interrupt happens, then this is when context switch happens, when scheduling works
    - a preemptive system only switched context by external interruptions

## Batch Scheduling

- charging
- First Come, First Served (FCFS)
- Short Job First (SJF)
- Priority
- CPU-bound vs. I/O-bound jobs
-













