#include <bits/stdc++.h>
using namespace std;

const int N = 40;
using ll = long long;


int n;
char a[N][N];
bool vi[N][N];

int dfs(int r, int c){
    vi[r][c] = true;
    int res = 1;
    for(int dr : {-1, 0, 1}) for(int dc : {-1, 0, 1}){
        if(abs(dr-dc) != 1) continue;
        //if(r == 1 and c == 1) cout << r << " " << c << " " << r+dr << " " << c+dc << " " << a[r+dr][c+dc] << " " << (!vi[r+dc][c+dc] and a[r][c] == '#' and a[r+dr][c+dc] == '.') << "\n";
        if(!vi[r+dr][c+dc] and a[r][c] == '.' and a[r+dr][c+dc] == '#') res += dfs(r+dr, c+dc);
        if(!vi[r+dr][c+dc] and a[r][c] == '#' and a[r+dr][c+dc] == '.') res += dfs(r+dr, c+dc);
    }
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(!vi[i][j]){
                int tmp = dfs(i, j);
                //cout << i << " " << j << " = " << tmp << "\n";
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}