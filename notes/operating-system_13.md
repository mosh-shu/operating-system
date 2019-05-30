# Operating System

## 20190530

- HDD... has a 4KB sector size
- user writes into a device through the kernel (device manager) 
- memory bus... main memory -> cache -> I/O controller
    1. define a variable
    2. write()
       1. allocate page on buffer cache
       2. copy from use space to kernel buffer-cache
       3. schedule I/O
       4. return

- DMA device... direct memory access device

- free block map... n block map n free/in use bits: stored in the disk itself
disk
|MBR|partition table|boot loader|actuawl partition (free block map around the onset) |

on disk inode
    time
    sizes
    owner
    mode
    block number for a file

1. allocate data block in free block map
2. write data
3. allocate inode in map
4. write inode
5. directory entry
