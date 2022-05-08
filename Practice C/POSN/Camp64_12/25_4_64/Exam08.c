#include<stdio.h>

int n;

int main(void){
    printf("Input Level : ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf(" ");
        }
        for(int j=1; j<=n; j++){
            if(i+j >= n+1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(int j=1; j<i; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i+j >= n+1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(int j=1; j<=n; j++){
            if(j < i){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(int j=1; j<=n; j++){
            if(i+j >= n+1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(int j=1; j<i; j++){
            printf("*");
        }
        printf("\n");
    }
}
