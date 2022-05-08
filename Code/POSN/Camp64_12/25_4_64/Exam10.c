#include<stdio.h>

int n;

int main(void){
    printf("Input Level : ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1; j++){
            printf(" ");
        }
        for(int j=1; j<=n; j++){
            if(i+j>n){
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
            if(i+j>n){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(int j=1; j<=n; j++){
            if(j<i){
                printf("*");
            }else{
                printf(" ");
            }
        }

        if(i == n){
            printf("*");
        }else{
            printf(" ");
        }
        printf(" ");

        for(int j=1; j<=n; j++){
            if(i+j>n){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(int j=1; j<=n; j++){
            if(j<i){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=n; j++){
            if(j > i){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(int j=1; j<n; j++){
            if(j+i < n){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("   ");

        for(int j=1; j<=n; j++){
            if(j > i){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(int j=1; j<n; j++){
            if(j+i < n){
                printf("*");
            }else{
                printf(" ");
            }
        }

            printf("\n");

    }

    //printf("HELLO");
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n+1; j++){
            printf(" ");
        }
        for(int j=1; j<=n; j++){
            if(j >= i){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(int j=1; j<=n-i; j++){
            printf("*");
        }
        printf("\n");
    }
}
