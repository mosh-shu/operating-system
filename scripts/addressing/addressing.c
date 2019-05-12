#include<stdio.h>
#include<stdlib.h>

int global;
 
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
    int *py, *pglobal;
    global = 4;
    y = sumLocal(global);
    pglobal = &global;
    py = &y;
    printf("pglobal = %p\n", pglobal);
    printf("py = %p\n", py);
    printf("*pglobal = %d\n", *pglobal);
    printf("*py = %d\n", *py);
}