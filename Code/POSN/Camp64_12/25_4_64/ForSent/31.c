#include<stdio.h>

int n;

int f(int num){
    if(num == 1)
        return 1;
    return num+f(num-1);
}
int g(int num){
    if(num == 1)
        return 2;
    return 2*num*g(num-1);
}
int h(int num){
    if(num == 1)
        return 1;
    return (2*num-1)+h(num-1);
}
int k(int num){
    if(num == 1)
        return 2;
    if(num == 2)
        return 3;
    return k(num-2)+k(num-1);
}

main(){
    printf("Input : ");
    scanf("%d", &n);
    printf("f(%d) = %d\n", n, f(n));
    printf("g(%d) = %d\n", n, g(n));
    printf("h(%d) = %d\n", n, h(n));
    printf("k(%d) = %d\n", n, k(n));
}
