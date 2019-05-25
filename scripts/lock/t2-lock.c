#include <stdio.h>
#include <assert.h>
#include <pthread.h>

#define COUNTER 100000000
int gcounter = COUNTER; /*1E8*/

pthread_mutex_t master_lock = PTHREAD_MUTEX_INITIALIZER;

void *mythread(void *arg)
{
    pthread_mutex_lock(&master_lock); //wrapper; exits on failure
    int lcounter = COUNTER / 2;       /*1E8*/
    printf("%s: start\n", (char *)arg);
    while (lcounter)
    {
        if (gcounter % 10000000 == 0)
        {
            printf("%s: %d\n", (char *)arg, gcounter);
        }
        gcounter--;
        lcounter--;
    }
    pthread_mutex_unlock(&master_lock);
    printf("lcounter: %d\n", lcounter);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t p1, p2;
    int rc;
    printf("main: begin\n");
    rc = pthread_create(&p1, NULL, mythread, "A");
    assert(rc == 0);
    rc = pthread_create(&p2, NULL, mythread, "B");
    assert(rc == 0);
    // join waits for the thread to finish
    printf("Okay, main() (our original thread) now waiting...\n");
    rc = pthread_join(p1, NULL);
    assert(rc == 0);
    rc = pthread_join(p2, NULL);
    assert(rc == 0);
    printf("gcounter: %d\n", gcounter);
    printf("main: end\n");
    return 0;
}
