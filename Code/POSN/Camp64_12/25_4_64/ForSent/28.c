#include<stdio.h>

int n=10,bs=0,ns=1;

int summation(int num){
    if(num == 1)
        return 1;
    return num+summation(num-1);
}

int main(void){

    printf("Input Number : ");
    scanf("%d", &n);

    printf("Summation 1st Method : %d\n", n*(n+1)/2);

    for(int i=ns; i<=n; i++){
        bs += i;
    }
    printf("Summation 2nd Method : %d\n", bs);

    printf("Summation 2nd Method : %d\n", summation(n));

    return 0;
}
