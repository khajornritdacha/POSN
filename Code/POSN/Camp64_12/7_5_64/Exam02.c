#include<stdio.h>

int n,a[110],mx1=0,mx2=0,mn1=0,mn2=0,mn=1e9,ok=0,okm=0,mx=0;

int abs(int x){
    if(x < 0)
        return x*-1;
    return x;
}
main(){
    for(int i=1; i<=10; i++){
        scanf("%d", &a[i]);
    }
    for(int i=1; i<10; i++){
        int j = i+1;
        if(abs(a[i]-a[j]) > mx){
            mx1 = i;
            mx2 = j;
            mx = abs(a[i]-a[j]);
            ok = 1;
        }else if(abs(a[i]-a[j]) == mx){
            ok++;
        }
        if(abs(a[i]-a[j]) < mn){
            mn1 = i;
            mn2 = j;
            mn = abs(a[i]-a[j]);
            okm = 1;
        }else if(abs(a[i]-a[j]) == mn){
            okm++;
        }
    }
    //printf("OK : %d %d\n", ok, okm);
    if(ok != 9 && okm != 9){
        printf("%d,%d,%d\n", a[mx1], a[mx2], abs(a[mx1]-a[mx2]));
        printf("%d,%d,%d\n", a[mn1], a[mn2], abs(a[mn1]-a[mn2]));
    }else{
        printf("N/A\n");
    }
}
