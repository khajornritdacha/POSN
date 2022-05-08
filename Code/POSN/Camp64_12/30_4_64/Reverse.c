#include<stdio.h>

int n,a[510];

main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
        if(a[i] <= 0){
            break;
        }
    }
    for(int i=n; i>=1; i--){
        if(a[i] > 0){
            printf("%d ", 2*a[i]);
        }
    }
}
