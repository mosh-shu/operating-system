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

## Page Replacement Algorithms

- OPT... the optimal algorithm to minimize the number of PAGE IN. It's just an idea, so we can't implement (we can't see the future)  
Here are the compromises:  
- LRU... Least Recently Used, a good compromise of OPT.
- NRU... Not Recently Used. The thing that you want to throw out, since you don't have to overwrite the file (no saving)
- Clock (second chance)... Go around the memory space, if "used", change the status to "unused" and increment the pointer. If you come back the next time and it's still "unused", use that space. It might get used while you go aruond the clock.
- 80-20 workload, looping workload

## Address Translation
- twp components in the virtual address
    - VPN: virtual page number
    - Offset: offset within the page
    - VPN is the part that translates virtual address to physical address, offset is like the "internal adress", so whatever the VPN is, it gets passed down
    - VPN -> Page Table Entry (PTE, 4MB/Table) -> PFN


