# オペレーティングシステム

### 20190422

## Memory

- 0xffff... 4 * 4 = 16-bit address space
- What is memory virtualization?
    - OS provides an illusion memory space per each process
    - It seems to be seen like each process uses the whole memory space 
    - -> Memory efficiency in terms of time and space, protection from erran acecesses of other processes (no worry about other processes, no need to know about other processes)
 - Addess Space
    - OS creates an abstraction of physical memory
    - The addess space contains all about a running process
    - Taht is consisted of program code, heap, stack and etc.
    - Stack... local variables
    - Heap... malloc things, dynamically allocated memory
    - Code... where instrucsions live
- Every adress in a running program is virtual
- After memory allocation, the memory has to be freed
- don't use strcpy... you wouldn't know how much memory will be used...
- use strncpy instead, or malloc beforehand
- dangling pointer... if you don't free space, pointer will be dangled

## Segmentation

- Memory virtualizing takes a similar strategy known as limited direct execution (LDE) for efficiency and control
- Adress Translation... process uses virtual address, hardware uses physical address
- A incremental program
    - Load a value from memory to register
    - Increment a value
    - Store the value back into memory
- Base and Bound Register
    - OS, not the processes, keeps information about base register and bounds register (where a virtual memory starts and end)
- The OS must save and restore the base-and-bounds pair
    - In process structure or process control block (PCB)

## Free-Space Management

- Finding a free chunk of memory that can satisfy the request and splitting it into two
- Free list... keeps track of free memory
- Coalescing free memory... merge several free chunks into a large single free chunk if addresses of them are nearby
- How would a library know what size of memory to free?.. most allocators actually has a header file to keep track of free space
- Management of free space
    - Best Fit: put malloc(6KB) to a 8KB space, instead of to a 16KB space
    - ... returns small chunks of memory
    - Worst Fit: put malloc (6KB) to a 16KB space, instead of to a 8 KB space
    - ... returns mid-size memory, ont space of large malloc
    - First Fit... First thing first



























