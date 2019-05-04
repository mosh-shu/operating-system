HW2.


prob1-1.txt describes the result of `./mlfq.py -s 1 -j 2 -M 0 -n 2 -m 50 -c`
prob1-2.txt describes the result of `./mlfq.py -s 2019 -j 2 -M 0 -n 2 -m 50 -c`
prob1-3.txt describes the result of `./mlfq.py -s 17523 -j 2 -M 0 -n 2 -m 50 -c`

prob2-1.txt describes the result of `./mlfq.py -l 0,200,0 -n 3 -c`
prob2-2.txt describes the result of `./mlfq.py -l 0,200,0:100,20,0 -n 3 -c`
prob2-3.txt describes the result of `./mlfq.py -l 0,200,0:50,38,1 -i 4 -n 3 -Sc`
prob2-4-1.txt describes the result of `./mlfq.py -l 0,200,0:100,100,5:100,100,5 -i 5 -Q 10,10,10 -Sc`
prob2-4-2.txt describes the result of `./mlfq.py -l 0,200,0:100,100,5:100,100,5 -i 5 -Q 10,10,10 -B 50 -Sc`
prob2-5.txt describes the result of `./mlfq.py -l 0,140,0:0,140,0 -Q 10,20,40 -A 2,2,2 -c`

4.a. 
Fairness index is defined as (Σ x_i)^2 / nΣx_i^2. Here, I define x_i = T_i / O_i, where T_i is basically turnaround - runTime. In this way, we could measure how equally delayed each tasks are. In practice, we subtract the "response" time from this value to take two equal length jobs into account (see prob3-0.txt). O_i is the "fair delay" for each job. If there is a case where job 0 requires only half of job 1's fairness, then O_0:O_1 will be 1:2. 
I got help from my classmate Ryosuke to determine the value of T_i, and the idea of "fair delay" is taken from the "fair throughput" of Raj Jain's lecture (https://www.cse.wustl.edu/~jain/atmf/ftp/af_fair.pdf). 

4.c. 
Answer is described in prob3-0.txt as a result of `./mlfq.py -l 0,100,0:0,100,0 -Q 10,10,10 -c`. Fairness is reported in the last line of the file.

4.d.
Answer is described in prob3-{1,2,3,4-1,4-2,5}.txt, accordingly to problem 2. Fairness is reported in the last line of the file.