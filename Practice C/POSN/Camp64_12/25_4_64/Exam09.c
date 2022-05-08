#include<stdio.h>

int n;

int main(void){
    printf("Enter Line : ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == n && j == n){
                printf("*");
            }else if(i+j > n){
                printf("+");
            }else{
                printf(" ");
            }
            printf(" ");
        }
        for(int j=1; j<i; j++){
            printf("+ ");
        }
        printf("\n");
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=n; j++){
            if(j > i){
                printf("+");
            }else{
                printf(" ");
            }
            printf(" ");
        }
        for(int j=1; j<n-i; j++){
            printf("+ ");
        }
        printf("\n");
    }
}
