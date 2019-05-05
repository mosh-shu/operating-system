HW2.

1. 
This file. prob{1,2,3}-*.txt corresponds to problems 2, 3, 4 in this homework. mlfq.py is the python file that was modified in problem 4.

2. 
prob1-1.txt describes the result of `./mlfq.py -s 1 -j 2 -M 0 -n 2 -m 50 -c`. Job 0 gets done within the first quantum, so job 1 keeps on going until it gets finished. After ten ticks (one quantum), job 1 gets lowered down to queue 0. Also, we can see that the reponse of job 1 is equal to the turnaround of job 0, 7. This is because job 1 starts immediately after job 0 is done.
prob1-2.txt describes the result of `./mlfq.py -s 2019 -j 2 -M 0 -n 2 -m 50 -c`. In this example, we can see job 0 and job 1 being processed in a "round-robin" behavior. Also, we can see that the response of job 1 is exactly 10, length of one quantum; in contrast to the previous example, where response of job 1 was equal to turnaround of job 0. 
prob1-3.txt describes the result of `./mlfq.py -s 17523 -j 2 -M 0 -n 2 -m 50 -c`. We could see that job 1 gets down within one quantum, thus letting job 0 start at time 19. 

3. 
prob2-1.txt describes the result of `./mlfq.py -l 0,200,0 -n 3 -c`. We could see that a single job gets passed down to the lower queue each quantum, until it reaches priority 0.  
prob2-2.txt describes the result of `./mlfq.py -l 0,200,0:100,20,0 -n 3 -c`. While Job 0 is running just like the previous example, job 1 cuts in at the highest queue. Job 1 gets finished within 2 quantums, never reaching queue 0, hence never showing the round-robin behavior with job 0. 
prob2-3.txt describes the result of `./mlfq.py -l 0,200,0:50,38,1 -i 4 -n 3 -Sc`. In this example, job 1 gets processed for 1 tick every five ticks. If should be noted that since it always gives up the CPU before a quantum ends, the "TICKS" count always stays at 9, and thus it stays at queue 2. 
prob2-4-1.txt describes the result of `./mlfq.py -l 0,200,0:100,100,5:100,100,5 -i 5 -Q 10,10,10 -Sc`. Job 1 and Job 2 both cuts in at time 100 and always gives up the CPU before a quantum ends. This keeps job 1 and job 2 at queue2, and since there is no boosting, job 0 gets "starved". 
prob2-4-2.txt describes the result of `./mlfq.py -l 0,200,0:100,100,5:100,100,5 -i 5 -Q 10,10,10 -B 50 -Sc`. In contrast to the previous example, this examples has the "boosting" system. Every 50 time units, all the jobs are moved to the highest queue, preventing some long running jobs, job 0 in this case, from getting starved. This creates a round-robin-"ish" manner, treating all the jobs more fairly than the previous example. Note: there seemed to be a bug in the code that did not allow proper boosting; please see the SFC-SFS message.
prob2-5.txt describes the result of `./mlfq.py -l 0,140,0:0,140,0 -Q 10,20,40 -A 2,2,2 -c`. In this example, there are two allotments for each queue. This allows a job to stay in its current queue after being processed for one quantum. We could also see that the quantum length varies for each queue, allowing a long run in queue 0. 

4.a. 
Fairness index is defined as (Σ x_i)^2 / nΣx_i^2. Here, I define x_i = T_i / O_i, where T_i is basically turnaround - runTime. In this way, we could measure how equally delayed each tasks are. In practice, we subtract the "response" time from this value to take two equal length jobs into account (see prob3-0.txt). O_i is the "fair delay" for each job. If there is a case where job 0 requires only half of job 1's fairness, then O_0:O_1 will be 1:2. 
I got help from my classmate, Ryosuke, to determine the value of T_i, and the idea of "fair delay" is taken from the "fair throughput" of Raj Jain's lecture (https://www.cse.wustl.edu/~jain/atmf/ftp/af_fair.pdf). 

4.c. 
Answer is described in prob3-0.txt as a result of `./mlfq.py -l 0,100,0:0,100,0 -Q 10,10,10 -c`. Fairness, which exactly is 1, is reported in the last line of the file.

4.d.
Answer is described in prob3-{1,2,3,4-1,4-2,5}.txt, accordingly to problem 2. Fairness is reported in the last line of the file.