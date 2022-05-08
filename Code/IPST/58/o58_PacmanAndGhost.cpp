#include<bits/stdc++.h>
using namespace std;
using tu = tuple<int,int,int>;
const int N = 1e2+10;
int a[N][N][5],pr[]={-1,1,0,0},pc[]={0,0,-1,1},R,C,T,n,sr,sc,test;
char ipt[N][N];
bool vi[N][N][5];
priority_queue<tu, vector<tu>, greater<tu>> pq;
void bfs(int code){
    while(!pq.empty()){
        auto [ti, nr, nc] = pq.top();
        pq.pop();
        for(int i=0; i<4; i++){
            int gr = nr+pr[i], gc = nc+pc[i];
            if(gr < 1 or gr > R or gc < 1 or gc > C)
                continue;
            if(ipt[gr][gc] == '#')
                continue;
            if(a[gr][gc][code] > a[nr][nc][code]+1){
                a[gr][gc][code] = a[nr][nc][code]+1;
                pq.emplace(a[gr][gc][code], gr, gc);
            }
        }
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> test;
    while(test--){
        bool ok = false;
        cin >> R >> C >> n >> T >> sr >> sc;
        sr++; sc++;
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                a[i][j][0] = a[i][j][1] = 1e9;
            }
        }
        for(int i=1; i<=n; i++){
            int tt,rr,cc;
            cin >> tt >> rr >> cc;
            rr++; cc++;
            pq.emplace(tt,rr,cc);
            a[rr][cc][0] = tt;
        }
        for(int i=1; i<=R; i++)
            for(int j=1; j<=C; j++)
                cin >> ipt[i][j];
        bfs(0);
        pq.emplace(0, sr, sc);
        a[sr][sc][1] = 0;
        bfs(1);
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(a[i][j][1] <= T and a[i][j][0] > T)
                    ok = true;
            }
        }
        /*for(int t=0; t<2; t++){
            cout << "round : " << t << "\n";
            for(int i=1; i<=R; i++){
                for(int j=1; j<=C; j++){
                    cout << a[i][j][t] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }*/
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
