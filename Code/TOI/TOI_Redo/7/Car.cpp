#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int a[N][N],ans[N],st,R,C;

bool dfs(int r, int c){
    if(r == R){
        for(int i = 0; i < r; i++)
            cout << ans[i] << "\n";
        return true;
    }

    if(c-1 >= 1 and a[r+1][c-1] == 0){
        ans[r] = 1;
        if(dfs(r+1, c-1)) return true;
    }

    if(c+1 <= C and a[r+1][c+1] == 0){
        ans[r] = 2;
        if(dfs(r+1, c+1)) return true;
    }

    if(a[r+1][c] == 0){
        ans[r] = 3;
        if(dfs(r+1, c)) return true;
    }

    return false;
}

int main(void){
    cin >> C >> st >> R;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
        }
    }

    dfs(0, st);

    return 0;
}