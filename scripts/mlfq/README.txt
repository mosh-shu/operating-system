HW2.


prob1-1.txt describes the result of `./mlfq.py -s 1 -j 2 -M 0 -n 2 -m 50 -c`
prob1-2.txt describes the result of `./mlfq.py -s 2019 -j 2 -M 0 -n 2 -m 50 -c`
prob1-3.txt describes the result of `./mlfq.py -s 17523 -j 2 -M 0 -n 2 -m 50 -c`

prob2-1.txt describes the result of `./mlfq.py -l 0,200,0 -M 0 -n 3 -c`
prob2-2.txt describes the result of `./mlfq.py -l 0,200,0:100,20,0 -M 0 -n 3 -c`
prob2-3.txt describes the result of `./mlfq.py -l 0,200,0:50,38,1 -i 4 -n 3 -Sc`
prob2-4-1.txt describes the result of `./mlfq.py -l 0,200,0:100,100,5:100,100,5 -i 5 -Q 10,10,10 -Sc`
prob2-5.txt describes the result of `./mlfq.py -l 0,140,0:0,140,0 -Q 10,20,40 -A 2,2,2 -c`

4.a. 
According to Raj Jain's lecture (https://www.cse.wustl.edu/~jain/atmf/ftp/af_fair.pdf), fairness index is (Σ x_i)^2 / nΣx_i^2 , where x_i = T_i / O_i; x_i is the normalized throughput, T_i is the measured throughput, and O_i is the fair throughput, for example, runTime. This O_i is helpful when there are jobs with varying lengths, since this normalizes the turnaround value. 

4.c.
Answer is described in prob3-0.txt as a result of `./mlfq.py -l 0,100,0:0,100,0 -Q 10,10,10 -c`. Fairness was 0.999.

4.d.







This measure is helpful when the number of jobs is fixed for the whole processing time ex.) prob2-5.txt. However, this measure becomes questionable when the number of jobs changes overtime like prob2-4-1.txt, i.e.) when job enters in and out. For example, in prob2-4-1.txt, x_0 is 400/200 = 2, x_1 is 195/100 = 1.95, and x_2 is 200/100 = 2. This seems very "fair" giving us a fairness value very close to 1, although job 1 is starving while jobs 2 and 3 are running, which is not a truly fair condition. This is because this measure ignores the reponsiveness at difference phases (number of jobs) and instead "averages out" the variance of responsiveness. 
Therefore, I propose to calculate fairness for each phase and then average them out. For example in prob2-4-1.txt, only job 0 is running for the first 100 ms, so the fairness should be 1, or x_1 = 100/100 = 1. T_0 is obviously 100, but what does O_0 =100 represent? It should be the expected throughput for each jobs when fairness is 1. In this case, there is only one job running in a 100 ms period, so O_0 should be 100/1 = 100. If there were two jobs running, O_0 and O_1 will each be 100/2 = 50. For the second time period, from 101ms to 300ms, where three jobs are processed, O_0-2 should be 200/3 = 67. Therefore, x_0 will be 0/67 = 0, x_1 will be 100/67 = 1.5, and x_2 will also be 1.5, so the total fairness will be (0+1.5+1.5)^2 / 3*(0+2.25+2.25) = 0.67. In the last 100ms (301-400ms), fairness will again be 1. By averaging these three numbers, we obtain a total fairness value of (1+0.67+1)/3 = 0.89, which is below 1 and is what we should get. 