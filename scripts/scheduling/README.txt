Schelduling

2. prob_1-[1-3].txt are the MLFQ execution trace. 
prob_1-1.txt is a result of `./multi.py -s 1 -n 1 -p 2 -j 2 -R 40 -tTSCc`. In this example, job 0 is immediately completed and job 1 is passed down to Q1. After 10 time units, the cache gets warmed up and the processing speed increases.
prob_1-2.txt is a result of `./multi.py -s 2 -n 1 -p 2 -j 2 -R 40 -tTSCc`. In this example, cache never warms up even though job 0 is processed for a sufficiently long period of time. This might seem bizzar until we realize that the rowking set size of job 0, 180, exceeds the cache size of 100; since data cannot be stored in cache, there is no possibility for the cache to be warmed up. Job 1 gets processed immediately.
prob_1-3.txt is a result of `./multi.py -s 2019 -n 1 -p 2 -j 2 -R 40 -tTSCc`. In this example, cache warms up for job 1 since its working set size does not exceed the cache size. However, since the cache "cools down" after 10 time units while context switch also happens after 10 times units, job 1 never gets to receive the benefit of warm cache. If we add `-q 5` option to change quantum to 5 time units (prob_1-4.txt), job 1 indeed does speed up. 
