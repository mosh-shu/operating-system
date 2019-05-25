#include <stdio.h>
#include <assert.h>
#include <pthread.h>

#define NUM_THREADS 10

int gcounter = 100000000; /* 1E8 */

typedef struct __counter_t
{
    int global;                     // global count
    pthread_mutex_t glock;          // global lock
    int local[NUMCPUS];             // local count (per cpu)
    pthread_mutex_t llock[NUMCPUS]; // ... and locks
    int threshold;                  // update frequency
} counter_t;

// init: record threshold, init locks, init values
//       of all local counts and gloval count

void init(counter_t *c, int threshold)
{
    c->threshold = threshold;
    c->global = 0;
    pthread_mutex_init(&c->glock, NULL);
    int i;
    for (i = 0; i < NUMCPUS; i++)
    {
        c->local[i] = 0;
        pthread_mutex_init(&c->llock[i], NULL);
    }
}

// update: usually, just grab local lock and update local amount
//         once local count has risen by 'threshold', grab gloval
//         lock and transfer local values to it
void update(counter_t *c, int threadID, int amt)
{
    int cpu = threadID % NUMCPUS;
    pthread_mutex_lock(&c->llock[cpu]);
    c->local[cpu] += amt; // assumes amt > 0
    if (c->local[cpu] >= c->threshold)
    { // transfer to global
        pthread_mutex_lock(&c->glock);
        c->global += c->local[cpu];
        pthread_mutex_unlock(&c->glock);
        c->local[cpu] = 0;
    }
    pthread_mutex_unlock(&c->llock[cpu]);
}

//get: just return global amount (which may not be perfect)
int get(counter_t *c)
{
    pthread_mutex_lock(&c->glock);
    int vat = c->global;
    pthread_mutex_unlock(&c->glock);
    return val; //only approximate
}

void *mythread(int *arg)
{
    int lcounter = gcounter / NUM_THREADS;
    int mythreadid = *(int *)arg;
    printf("%d: start\n", mythreadid;
    while (lcounter)
    {
        if (get(&global_counter) % 10000000 == 0 && get(&global_counter) > 0)
            printf("%s: %d\n", (char *)arg, gcounter);
        update(&global_counter, mythreadid, +1); /* call the shared counter's update routine */
        lcounter--;
    }
    printf("lcounter: %d\n", lcounter);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc;
    int threadid = 0;
    printf("main: begin\n");

    /* First, initialize our shared counter structure; 1000000 is the "threshold", how often the local values update the global */
    init(&global_counter, 1000);

    /* create our threads and fire them off */
    for (int i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_create(&threads[i], NULL, mythread, &threadid);
        assert(rc == 0);
        threadid++;
    }

    // join waits for the threads to finish
    printf("Okay, main() (our original thread) now waiting...\n");
    for (int i = 0; i < NUM_THREADS; i++)
    {
        rc = pthread_join(threads[i], NULL);
        assert(rc == 0);
    }
    printf("get(&global_counter): %d\n", get(&global_counter));
    printf("main: end\n");
    return 0;
}
