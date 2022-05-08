#include<bits/stdc++.h>
using namespace std;
const int N = 1e2;
int mx,R,C,cnt,pr[]={-1,1,0,0},pc[]={0,0,-1,1};
char ta[N][N],ne[N][N];
void dfs(int r, int c){
    cnt++;
    ne[r][c] = '#';
    for(int i=0; i<4; i++){
        if(ne[r+pr[i]][c+pc[i]] == '.'){
            dfs(r+pr[i], c+pc[i]);
        }
    }
}
main(){
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> ta[i][j];
            ne[i][j] = '.';
        }
    }
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(ta[i][j] == '#')
                ne[i+1][j] = ne[i-1][j] = ne[i][j-1] = ne[i][j+1] = ne[i][j] = '#';
        }
    }
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(ne[i][j] == '.'){
                cnt = 0;
                dfs(i, j);
                mx = max(mx, cnt);
                //cout << i << " " << j << " " << cnt << "\n";
            }
        }
    }
    cout << mx;
}
