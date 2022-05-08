#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int pr[]={0,1,0,-1},pc[]={-1,0,1,0},C,R,a[N][N];

void dfs(int r, int c){
    if(r >= 0 and c >= 0 and r < R and c < C){
        if(a[r][c] == 1 or a[r][c] == 2)
            return;
        if(a[r][c] == 3){
            for(int i=0; i<R; i++){
                for(int j=0; j<C; j++){
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            return;
        }
        if(a[r][c] == 0 or a[r][c] == 4){
            a[r][c] = 2;
            dfs(r, c-1);
            dfs(r+1, c);
            dfs(r, c+1);
            dfs(r-1, c);
            a[r][c] = 0;
        }
    }
    return;
}
main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> a[i][j];
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(a[i][j] == 4)
                dfs(i, j);
        }
    }
}
