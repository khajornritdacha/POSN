#include <bits/stdc++.h>
using namespace std;

using pi = pair<int,int>;
const int N = 2010;

int R,C,ans;
char a[N][N];
queue<pi> qq;

void bfs(int sr, int sc){
    qq.emplace(sr, sc);
    a[sr][sc] = '0';
    while(!qq.empty()){
        auto [r, c] = qq.front(); qq.pop();
        
        for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
            if(a[r+dr][c+dc] == '1'){
                a[r+dr][c+dc] = '0';
                qq.emplace(r+dr, c+dc);
            }
        }
    }
}

int main(void){
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(a[i][j] == '1'){
                bfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;   
}