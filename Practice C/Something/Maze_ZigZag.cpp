#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e3+10;

int a[N][N],n;

void dfs(int i = n, int j = 1, int di = 0, int cnt = 1){
    a[i][j] = cnt++;
    if(i == 1 and j == n)
        return;
    if(!di){
        if(i-1 >= 1 and j-1 >= 1)
            dfs(i-1, j-1, di, cnt);
        else if(i-1 >= 1)
            dfs(i-1, j, !di, cnt);
        else
            dfs(i, j+1, !di, cnt);
    }else{
        if(i+1 <= n and j+1 <= n)
            dfs(i+1, j+1, di, cnt);
        else if(j+1 <= n)
            dfs(i, j+1, !di, cnt);
        else
            dfs(i-1, j, !di, cnt);
    }
}

main(){
    scanf("%d", &n);
    dfs();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
}
