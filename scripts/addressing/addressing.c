#include<stdio.h>
#include<stdlib.h>

int global;
int global2;
 
int sumLocal(int x) {
    int a = 3;
    int b = 2;
    int *pa, *pb;
    pa = &a;
    pb = &b;
    int sum = a + b;
    int ans = sum * x;
    printf("ans = %d\n", ans);
    printf("pa = %p\n", pa);
    printf("pb = %p\n", pb);
    printf("*pa = %d\n", *pa);
    printf("*pb = %d\n", *pb);
    return ans;
}
 
int main() {
    int y;
    int *py, *pglobal, *pglobal2, (*psumLocal)(int);
    global = 4;
    global2 = 5;
    y = sumLocal(global);
    pglobal = &global;
    pglobal2 = &global2;
    py = &y;
    psumLocal = sumLocal;
    printf("pglobal = %p\n", pglobal);
    printf("pglobal2 = %p\n", pglobal2);
    printf("py = %p\n", py);
    printf("psumLocal = %p\n", psumLocal);
    printf("*pglobal = %d\n", *pglobal);
    printf("*pglobal2 = %d\n", *pglobal2);
    printf("*py = %d\n", *py);
}