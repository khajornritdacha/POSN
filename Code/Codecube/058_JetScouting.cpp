#include<bits/stdc++.h>
using namespace std;

const int N = 3e2+10;
using tu = tuple<int,int,int,int>;
int R,C,Q,dis[N][N][8],str,stc,pr[]={-1,-1,0,1,1,1,0,-1},pc[]={0,1,1,1,0,-1,-1,-1};
vector<int> cha[8];
char a[N][N];
priority_queue<tu, vector<tu>, greater<tu>> pq;

bool ok(int r, int c){
    if(r >= 1 and r <= R and c >= 1 and C <= C and a[r][c] != '#')
        return true;
    return false;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cha[0]=cha[4]={2,6}, cha[2]=cha[6]={0,4}, cha[1]={7,3}, cha[3]={1,5}, cha[5]={3,7}, cha[7]={1,5};
    cin >> R >> C >> Q;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> a[i][j];
            if(a[i][j] == 'J'){
                str = i, stc = j;
            }
        }
    }

    for(int i=0; i<=R; i++) for(int j=0; j<=C; j++) for(int k=0; k<8; k++) dis[i][j][k] = 1e9;

    for(int i=0; i<8; i++){
        dis[str][stc][i] = 0;
        int nr = pr[i]+str, nc = pc[i]+stc;
        if(ok(nr, nc)){
            dis[nr][nc][i] = 0;
            pq.emplace(0, nr, nc, i);
        }
    }

    while(!pq.empty()){
        auto [wa, nr, nc, code] = pq.top();
        pq.pop();

        int gr = nr+pr[code], gc = nc+pc[code];
        if(ok(gr, gc) and dis[nr][nc][code] < dis[gr][gc][code]){
            dis[gr][gc][code] = dis[nr][nc][code];
            pq.emplace(dis[gr][gc][code], gr, gc, code);
        }

        for(int cc : cha[code]){
            gr = nr+pr[cc], gc = nc+pc[cc];
            if(ok(gr, gc) and dis[nr][nc][code]+1 < dis[gr][gc][cc]){
                dis[gr][gc][cc] = dis[nr][nc][code]+1;
                pq.emplace(dis[gr][gc][cc], gr, gc, cc);
            }
        }
    }

    while(Q--){
        int r,c;
        cin >> r >> c;
        int ans = *min_element(dis[r][c], dis[r][c]+8);
        if(ans == 1e9)
            ans = -1;
        cout << ans << "\n";
    }
}
