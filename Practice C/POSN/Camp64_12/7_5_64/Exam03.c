#include<stdio.h>

int a[10],n=8,m,chk=0;

main(){
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for(int i=1; i<=n; i++){
        if(a[i]+m <= 50){
            printf("%d ", i);
            chk = 1;
        }
    }
    if(chk == 0)
        printf("0");
}
