#include<stdio.h>

int n;

int main(void){
    printf("Input Number : ");
    scanf("%d", &n);
    printf("Result is : ");
    if(n%2 == 1){
        printf("%d", n*n*n);
    }else{
        printf("%d", n*n);
    }
}
