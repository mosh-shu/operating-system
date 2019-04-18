# オペレーティングシステム

### 20190418

## MLFQ

- Multi Level Feedback Queue
- Queue... line of jobs (ppl) waiting to be done
- 1. A job on a queue with higher priority is chosen to run
- 2. In the same queue, job is done round-robin scheduling (A->B->C->A->B->...)
- 3. MLFQ varies the priority of a job based on its observed behavior
    - a job repeatedly relinquished the CPU while waiting IOs ... keeping its priority high
    - A job uses the CPU intetensivelty for a long time... lower its priority
- 4. When a job enters the system, it is placed at the  highest priority
- 5. after some time perios S, move all the jobs in the system to the top most queue
- Approcximates SJF
- Keeps interactive job at the highest priority
- Problems
    - Starvation: if there are "too many" interactive jobs in the system. Long running jobs will neber receive any CPI time.
    - Game the scheduler: Afer 99% of a time slice, issue an I/O operation
    - Changed behavior: I/O process, so not as expected?

## Trees

- Trees are amazing
- good trees could search in log(N) time
- red-black tree reshapes linear trees to a good tree?
- complete fair scheduler is based on red-black trees




