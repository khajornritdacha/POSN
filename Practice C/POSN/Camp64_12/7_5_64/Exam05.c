#include<stdio.h>

int n,a[1010],cnt=0,chk[1010]={};

main(){
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    while(1){
        int mn = 1e9,p1=0,p2=0;
        for(int i=1; i<=n; i++){
            for(int j=i+1; j<=n; j++){
                if(chk[i] == 0 && chk[j] == 0 && a[i]+a[j] < mn && a[i]+a[j] <= 240){
                    mn = a[i]+a[j];
                    p1 = i;
                    p2 = j;
                }
            }
        }
        if(mn != 1e9){
            chk[p1] = 1;
            chk[p2] = 1;
            printf("R#%d - Movie%d Movie%d\n", ++cnt, p1, p2);
        }else{
            for(int i=1; i<=n; i++){
                if(chk[i] == 0 && a[i] < mn){
                    mn = a[i];
                    p1 = i;
                }
            }
            if(mn != 1e9){
                chk[p1] = 1;
                printf("R#%d - Movie%d\n", ++cnt, p1);
            }else{
                break;
            }
        }
    }
}
