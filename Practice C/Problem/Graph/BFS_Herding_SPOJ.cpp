#include <bits/stdc++.h>
using namespace std;

const int N = 1010,INF = 1e9;
using ll = long long;
using pi = pair<int,int>;

int vi[N][N],R,C,num[N][N],cnt;
char ta[N][N];

///https://www.spoj.com/problems/HERDING/

void dfs(int i, int j){
    vi[i][j] = 1;
    int dr = 0, dc = 0;
    if(ta[i][j] == 'N') dr = -1;
    else if(ta[i][j] == 'S') dr = 1;
    else if(ta[i][j] == 'W') dc = -1;
    else if(ta[i][j] == 'E') dc = 1;

    if(vi[i+dr][j+dc] == 1){
        num[i][j] = ++cnt;
    } else if (vi[i+dr][j+dc] == 2){
        num[i][j] = num[i+dr][j+dc];
    } else {
        dfs(i+dr, j+dc);
        num[i][j] = num[i+dr][j+dc];
    }
    vi[i][j] = 2;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> ta[i][j];
        }
    }

    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(!num[i][j]){
                dfs(i, j);
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}
