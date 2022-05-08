#include <bits/stdc++.h>
using namespace std;

const int N = 30, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

int len,R,C,a[N][N], dr[25][2], dc[25][2];
vector<int> ans;

bool cu(int r, int c){ return (a[r][c] == 13 or a[r][c] == 14 or a[r][c] == 21 or a[r][c] == 31); }
bool cd(int r, int c){ return (a[r][c] == 11 or a[r][c] == 12 or a[r][c] == 21 or a[r][c] == 31); }
bool cl(int r, int c){ return (a[r][c] == 12 or a[r][c] == 14 or a[r][c] == 22 or a[r][c] == 31); }
bool cr(int r, int c){ return (a[r][c] == 11 or a[r][c] == 13 or a[r][c] == 22 or a[r][c] == 31); }

void dfs(int r, int c, int di){ //di = 1 -> vertical, di = 0 -> horizontal
    int tmp = a[r][c];
    len++;
    //cout << len << " " << r << " " << c << " " << di << "\n";
    if(a[r][c] != 31) a[r][c] = 0;
    else a[r][c] = (di) ? 22 : 21;

    if(tmp == 31) tmp = (di) ? 21 : 22;

    for(int i = 0; i < 2; i++){
        int gr = r+dr[tmp][i], gc = c+dc[tmp][i];
        if(dr[tmp][i] == -1 and cu(gr, gc)){
            dfs(gr, gc, 1);
        }else if(dr[tmp][i] == 1 and cd(gr, gc)){
            dfs(gr, gc, 1);
        }else if(dc[tmp][i] == -1 and cl(gr, gc)){
            dfs(gr, gc, 0);
        }else if(dc[tmp][i] == 1 and cr(gr, gc)){
            dfs(gr, gc, 0);
        }
    }
    return;
}

int main(void){
    {
        dr[11][0] = -1, dc[11][0] = 0;
        dr[11][1] = 0, dc[11][1] = -1;
        
        dr[12][0] = -1, dc[12][0] = 0;
        dr[12][1] = 0, dc[12][1] = 1;

        dr[13][0] = 0, dc[13][0] = -1;
        dr[13][1] = 1, dc[13][1] = 0;

        dr[14][0] = 0, dc[14][0] = 1;
        dr[14][1] = 1, dc[14][1] = 0;

        dr[21][0] = -1, dr[21][1] = 1;
        dc[22][0] = -1, dc[22][1] = 1;
    }

    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
        }
    }    

    for(int j = 1; j <= C; j++){
        if(cd(1, j)){
            len = 0;
            dfs(1, j, 1);
            ans.emplace_back(len);
        }
    }

    for(int j = 1; j <= C; j++){
        if(cu(R, j)){
            len = 0;
            dfs(R, j, 1);
            ans.emplace_back(len);
        }
    }

    for(int i = 1; i <= R; i++){
        if(cr(i, 1)){
            len = 0;
            dfs(i, 1, 0);
            ans.emplace_back(len);
        }
    }

    for(int i = 1; i <= R; i++){
        if(cl(i, C)){
            len = 0;
            dfs(i, C, 0);
            ans.emplace_back(len);
        }
    }

    cout << ans.size() << "\n";
    for(int an : ans) cout << an << " ";
    cout << "\n";

    return 0;
}