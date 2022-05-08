#include<stdio.h>

int n,cnt=0;

int main(void){
    printf("N = ");
    scanf("%d", &n);
    for(int i=1; i<=n+1; i++){
        cnt = 0;
        for(int j=1; j<=n+1; j++){
            if(i+j > n+1){
                printf("%d",cnt);
                cnt++;
            }else{
                printf(" ");
            }
        }
        cnt = i-1;
        for(int j=1; j<i; j++){
            cnt--;
            printf("%d",cnt);
        }
        printf("\n");
    }
    for(int i=1; i<=n; i++){
        cnt = 0;
        for(int j=1; j<=n+1; j++){
            if(j > i){
                printf("%d",cnt);
                cnt++;
            }else{
                printf(" ");
            }
        }
        cnt = n-i-1;
        for(int j=1; j<=n-i; j++){
            printf("%d",cnt);
            cnt--;
        }
        printf("\n");
    }
}
