All the program is written in `addressing.c`, compiled as `addressing.out`, and outputted to `addressing.txt`. 

Memory adress map is recorded in smaps.txt, which was obtained by the following procedure.
1. compile with `gcc addressing.c -o addressing.out -Wall`
2. run the process in the background with `./addressing.out > addressing.txt &`.
3. While `./addressing.out` is running (sleeps for 60 secs), run `ps` and get the process ID for `./addressing.out`
4. run `cat /proc/<PID>/smaps > smaps.txt` to obtain a memory map.

From addressing.txt, we could see that the stack on the system "grows up". Also, we could see that global variables with their value given before the main() call get stored in the memory earlier. 
From smaps.txt, we could see that
- functions are assinged in the first two segments,
- global variable are assinged in the next (third) segment,
- malloc()ed variables are assinged in the next (fourth) segment, and that
- local variables are stored in stack.