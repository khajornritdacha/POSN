#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
int cnt = 0,R,C,ans[N][N],pr[]={-1,0,1,0},pc[]={0,1,0,-1};
char a[N][N];
bool visit[N][N];

void dfs(int r, int c){
    ans[r][c] = cnt;
    visit[r][c] = true;
    //cout << r << " " << c << "\n";
    for(int i=0; i<4; i++){
        int gr = r+pr[i], gc = c+pc[i];
        if(gr < 1 or gr > R or gc < 1 or gc > C) continue;
        if(visit[gr][gc]) continue;
        if(a[gr][gc] == '0') continue;
        dfs(gr, gc);
    }
}

main(){
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> a[i][j];
        }
    }

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(visit[i][j] == false and a[i][j] == '1'){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << "ANS\n";
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
