1. compile with `gcc addressing.c -o addressing.out -Wall`
2. run the process in the background with `./addressing.out > addressing.txt &`.
3. While `./addressing.out` is running (sleeps for 60 secs), run `ps` and get the process ID for `./addressing.out`
4. run `cat /proc/<PID>/smaps > smaps.txt` to obtain a memory map.


