#include<stdio.h>

int n;

int main(void){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=(n-i)*2; j++){
            printf(" ");
        }
        for(int j=1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=i*2; j++){
            printf(" ");
        }
        for(int j=1; j<=n-i; j++){
            printf("*");
        }
        printf("\n");
    }
}
