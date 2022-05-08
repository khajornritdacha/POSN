#include<stdio.h>

int n,m,ans,idx=0,arr[10]={};

int main(void){
    printf("Input first Number : ");
    scanf("%d", &n);
    printf("Input second Number : ");
    scanf("%d", &m);
    ans = n+m;
    while(ans > 0){
        arr[idx] = ans%10;
        ans/=10;
        idx++;
    }
    printf("Result is\n");
    for(int i=3; i>=0; i--){
        printf("%d\n", arr[i]);
    }
}
