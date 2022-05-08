#include<stdio.h>

int n;

int main(void){
    printf("Enter Line : ");
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        for(int j=1; j<=n; j++){
            if(i+j == n+1){
                printf("%d", i);
            }else{
                printf(" ");
            }
            printf(" ");
        }
        for(int j=1; j<i; j++){
            if(j == i-1){
                printf("%d", i);
            }else{
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
    for(int i=1; i<2*n; i++){
        printf("%d ", n);
    }
}
