#include <stdio.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// thread argument
struct tharg{
    char name[10]; // bad, bad, bad boy... fixed length without #define
    int val; //out value to "sort"... how long we'll sleep
};

void *mythread(void * arg){
    struct tharg *targ = (struct tharg *)arg;
    printf("in mythread\n");
    printf("%s: start\n", targ->name);
    sleep(targ->val); // ooh, what happens if this is negative?
    printf(" %d", targ->val); fflush(stdout);
    free(arg); // wow, malloced above, freed here, bad practice
    return NULL;
}

int datalist[] = {1, 5, 2, 23, 11};

int main(int argc, char *argv[]){
    pthread_t *pthreads;
    int rc, i;
    unsigned long listlen = sizeof(datalist)/sizeof(int);
    printf("main: begin sorting list of %lu numbers\n", listlen);
    pthreads = malloc(sizeof(pthread_t)*listlen);
    if (!pthreads){
        printf("fail! abort!\n");
        exit(-1);
    }
    for (i=0; i<listlen; i++){
        struct tharg *t = (struct tharg *)malloc(sizeof(struct tharg));
        printf("i: %d\n", i);
        if (!t){
            printf("fail! abort!\n");
            exit(-1);
        }
        sprintf(t->name, "T: %d", i);
        t->val = datalist[i];
        // a bad idea--- I'm just losing the pointer to t here, letting the thread free() it
        rc = pthread_create(&pthreads[i], NULL, mythread, t); assert(rc == 0);
    }
    // join waits for the thread to finish
    printf("Okay, main() (our original thread) now waiting...\n");
    for (i=0; i<listlen; i++){
        rc = pthread_join(pthreads[i], NULL); assert(rc==0);
    }
    printf("\nmain: end\n");
    return 0;
}