#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
long long a[55][55],n,m,o;
bool visit[55][55];
queue<pi> qq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> o;
    for(int i=0;i<o;i++){
        int x,y;
        cin >> y >> x;
        a[n-x+1][y] = -1;
    }
    a[n][1] = 1;
    qq.emplace(n,1);
    while(!qq.empty()){
        pi now = qq.front();
        visit[now.first][now.second] = true;
        qq.pop();
        int pr[]={-1,0},pc[]={0,1};
        for(int i=0;i<2;i++){
            int nr = now.first+pr[i];
            int nc = now.second+pc[i];
            if(nr<1||nc<1||nr>n||nc>m)
                continue;
            if(a[nr][nc]==-1)
                continue;
            a[nr][nc]+=a[now.first][now.second];
            if(!visit[nr][nc]){
                qq.emplace(nr,nc);
                visit[nr][nc] = true;
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }*/
    cout << a[1][m];
}
