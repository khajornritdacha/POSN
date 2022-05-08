#include<stdio.h>

int n=10,bs=0,ns=1;

int summation(int num){
    if(num == ns)
        return ns;
    return num+summation(num-1);
}

int main(void){

    printf("Input Range of Sum : ");
    scanf("%d %d", &ns, &n);

    printf("Summation 1st Method : %d\n", (n*(n+1)/2)-(ns*(ns-1)/2));

    for(int i=ns; i<=n; i++){
        bs += i;
    }
    printf("Summation 2nd Method : %d\n", bs);

    printf("Summation 2nd Method : %d\n", summation(n));

    return 0;
}
