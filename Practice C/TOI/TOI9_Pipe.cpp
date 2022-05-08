#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+10;
int m,n,b[N][N],len;
vector<int> ans;

void dfs(int r, int c, int pr, int pc){
    int tmp = b[r][c];
    if(pr >= 1 and pr <= m and pc >= 1 and pc <= n){
        if(b[pr][pc] == 31){
            if(pr == r)
                b[pr][pc] = 21;
            else
                b[pr][pc] = 22;
        }else{
            b[pr][pc] = 0;
        }
    }
    len++;
    if(r == 0 or r == m+1 or c == 0 or c == n+1){
        ans.emplace_back(len-1);
        return;
    }
    if(tmp == 11){
        if(c == pc){
            return dfs(r, c-1, r, c);
        }else{
            return dfs(r-1, c, r, c);
        }
    }else if(tmp == 12){
        if(c == pc){
            return dfs(r, c+1, r, c);
        }else{
            return dfs(r-1, c, r, c);
        }
    }else if(tmp == 13){
        if(c == pc){
            return dfs(r, c-1, r, c);
        }else{
            return dfs(r+1, c, r, c);
        }
    }else if(tmp == 14){
        if(c == pc){
            return dfs(r, c+1, r, c);
        }else{
            return dfs(r+1, c, r, c);
        }
    }else if(tmp == 21){
        if(pr > r){
            return dfs(r-1, c, r, c);
        }else{
            return dfs(r+1, c, r, c);
        }
    }else if(tmp == 22){
        if(pc > c){
            return dfs(r, c-1, r, c);
        }else{
            return dfs(r, c+1, r, c);
        }
    }else if(tmp == 31){
        if(pr > r){
            return dfs(r-1, c, r, c);
        }else if(pr < r){
            return dfs(r+1, c, r, c);
        }else if(pc > c){
            return dfs(r, c-1, r, c);
        }else{
            return dfs(r, c+1, r, c);
        }
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> b[i][j];
        }
    }

    ///This order is important!!!
    for(int j=1; j<=n; j++){
        len = 0;
        if((b[1][j] == 11 or b[1][j] == 12 or b[1][j] ==  21 or b[1][j] == 31)){
            dfs(1, j, 0, j);
        }
    }
    for(int j=1; j<=n; j++){
        len = 0;
        if((b[m][j] == 13 or b[m][j] == 14 or b[m][j] == 21 or b[m][j] == 31)){
            dfs(m, j, m+1, j);
        }
    }
    for(int i=1; i<=m; i++){
        len = 0;
        if((b[i][1] == 11 or b[i][1] == 13 or b[i][1] == 22 or b[i][1] == 31)){
            dfs(i, 1, i, 0);
        }
    }
    for(int i=1; i<=m; i++){
        len = 0;
        if((b[i][n] == 12 or b[i][n] == 14 or b[i][n] == 22 or b[i][n] == 31)){
            dfs(i, n, i, n+1);
        }
    }
    cout << ans.size() << "\n";
    for(int an : ans){
        cout << an << " ";
    }
}
