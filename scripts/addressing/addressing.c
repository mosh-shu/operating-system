#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int global;
int global2;
int global3 = 5;
int global4 = 6;

int add(int x);
int sub(int x);

int main() {
    int ya, ys;
    int *pya, *pys, *pglobal, *pglobal2, *pglobal3, *pglobal4;
    int (*padd)(int), (*psub)(int);
    int *m1, *m2;

    global = 4;
    global2 = 8;

    ya = add(global);
    ys = sub(global2);

    pglobal = &global;
    pglobal2 = &global2;
    pglobal3 = &global3;
    pglobal4 = &global4;
    pya = &ya;
    pys = &ys;
    padd = &add;
    psub = &sub;

    m1 = malloc(20);
    m2 = malloc(20);

    printf("\nPointers to global variables: \n");
    printf("\tpglobal = %p\n", pglobal);
    printf("\tpglobal2 = %p\n", pglobal2);
    printf("\tpglobal3 = %p\n", pglobal3);
    printf("\tpglobal4 = %p\n", pglobal4);
    printf("\nPointers to local variables: \n");
    printf("\tpya = %p\n", pya);
    printf("\tpys = %p\n", pys);
    printf("\nPointers to functions: \n");
    printf("\tpadd = %p\n", padd);
    printf("\tpsub = %p\n", psub);
    printf("\tm1 = %p\n", m1);
    printf("\tm2 = %p\n", m2);

    printf("\nValues of each variables\n");
    printf("*pglobal = %d\n", *pglobal);
    printf("*pglobal2 = %d\n", *pglobal2);
    printf("*pgloba3 = %d\n", *pglobal3);
    printf("*pglobal4 = %d\n", *pglobal4);
    printf("*pya = %d\n", *pya);
    printf("*pys = %d\n", *pys);
    printf("(*padd)(global) = %d\n", (*padd)(global));
    printf("(*psub)(global2) = %d\n", (*psub)(global2));
    printf("*m1 = %d\n", *m1);
    printf("*m2 = %d\n", *m2);
    printf("\n");

    sleep(60);
}

int add(int x) {
    int a = 2;
    int b = 3;
    int sum = a + b;
    int ans = sum * x;
    return ans;
}

int sub(int x) {
    int a = 2;
    int b = 3;
    int sum = a - b;
    int ans = sum * x;
    return ans;
}