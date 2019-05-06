# オペレーティングシステム

### 20190506

## Paging

- process emits cvirtual adress -> MMU (memory managing unit) & page table -> gets converted into physical address -> memory bus -> process 
- 32 bits can express 2^32 adresses 

## Memory Pressure and Reference Trace

- Memory pressure... when you don't have enough memory space and you have to push out some stuff
- Reference trace... 
- where things are stored
    - arguments (or its pointers)... stack or registers
    - local variable... stack or maybe register
    - array itself... heap (the big space between program and stack)
- memory trace ... trace of memory being accessed
    1. sum: 0x1000-0x1020
    2. a[3]: 0x400c (access to variable)
    3. 0x1008 (read the code)
    4. 0x1012 (read the code)
    3. a[2]: 0x4008 (access to variable)
- 


