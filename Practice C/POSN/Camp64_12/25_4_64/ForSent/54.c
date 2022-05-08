#include<stdio.h>

int n,ta[30][10030],ans,nc[30]={}, mx=0;

int fibo(int lv, int dep){
    //printf("%d %d\n", lv, dep);
        if(dep > mx)
            mx = dep;
    if(lv <= 1){
        while(dep <= mx){
            ta[dep][nc[dep]++] = lv;
            dep++;
        }
        return 1;
    }
    ta[dep][nc[dep]++] = lv;
    return fibo(lv-1, dep+1)+fibo(lv-2, dep+1);
}

main(){
    printf("Input Number : ");
    scanf("%d", &n);
    int ans = fibo(n,0);
    printf("Fibo(%d)\n", n);
    for(int i=1; i<=mx; i++){
        printf("= ");
        for(int j=0; j<nc[i]; j++){
            printf("Fibo(%d) ", ta[i][j]);
            if(j < nc[i]-1)
                printf("+ ");
        }
        printf("\n");
    }
    printf("= ");
    for(int i=0; i<nc[mx]; i++){
        printf("1 ");
        if(i < nc[mx]-1)
            printf("+ ");
    }
    printf("\n");
    printf("%d\n",ans);
}
