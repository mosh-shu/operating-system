Schelduling

2. prob_1-[1-3].txt are the MLFQ execution trace. 
prob_1-1.txt is a result of `./multi.py -s q -n 2 -j 2 -R 40 -q 5 -tTSCc`. From this example, we can see that job 1 is switched to CPU 0 after the first quantum has passed, and that the short quantum of 5 unit time is enabling the cache to warmup earlier rather than setting quantime to 10 unit time.
prob_1-2.txt is a result of `./multi.py -s 2 -n 2 -j 2 -R 40 -tTCSc`. From this example, we can see that the cache never warms up. This might seem a little bit weird; however, if we can spot that the working set size of 180 exceeds the cache size of 100, it makes sense that the cache cannot hold appropriate data and thus is never will warm up.
prob_1-3.txt is a result of `./multi.py -s 23 -n 2 -j 2 -R 40 -tTCSc`. Although the run time of job 0 and job 1 is both equally 30 time units, job 1 gets processed faster since is cache gets warmed up while job 0 is always slow because the cache does not get warmed up. Again, this is dues to the difference in working set size; job 0 holds a value of 180 which is larger than the cache size while job 1 holds 10 that is small enough to be stored in cache.
 

