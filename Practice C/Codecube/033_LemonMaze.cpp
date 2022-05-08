#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 3e2+10;
using tu = tuple<int,int,int>;
using tu2 = tuple<int,int,int,int>;
int R,C,str,stc,edr,edc,dis[N][N][4],pr[]={-1,0,1,0},pc[]={0,1,0,-1};
bool ok[N][N][4],chk[N][N][4][4];
char a[N][N];
vector<tu> saber;
queue<tu> qq;
priority_queue<tu2, vector<tu2>, greater<tu2>> pq;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> a[i][j];
            if(a[i][j] == 'S'){
                str = i, stc = j;
            }else if(a[i][j] == 'E'){
                edr = i, edc = j;
            }else if(a[i][j] == '|'){
                saber.emplace_back(i, j, 0);
            }else if(a[i][j] == '/'){
                saber.emplace_back(i, j, 1);
            }else if(a[i][j] == '-'){
                saber.emplace_back(i, j, 2);
            }else if(a[i][j] == '\\'){
                saber.emplace_back(i, j, 3);
            }
            for(int t=0; t<4; t++)
                dis[i][j][t] = 1e9;
        }
    }
    for(int t=0; t<4; t++){
        for(auto [r,c,cd] : saber){
            qq.emplace(r, c, (cd+t)%4);
        }
        while(!qq.empty()){
            auto [r, c, cd] = qq.front();
            qq.pop();

            chk[r][c][t][cd] = true;
            int gr = r,gc = c;
            if(cd == 0){
                gr = r-1, gc = c;
            }else if(cd == 1){
                gr = r-1, gc = c+1;
            }else if(cd == 2){
                gr = r, gc = c-1;
            }else if(cd == 3){
                gr = r-1, gc = c-1;
            }
            if(gr >= 1 and gr <= R and gc >=1 and gc <= C and a[gr][gc] == '.' and !chk[gr][gc][t][cd]){
                chk[gr][gc][t][cd] = true;
                qq.emplace(gr, gc, cd);
            }
            gr = r, gc = c;
            if(cd == 0){
                gr = r+1, gc = c;
            }else if(cd == 1){
                gr = r+1, gc = c-1;
            }else if(cd == 2){
                gr = r, gc = c+1;
            }else if(cd == 3){
                gr = r+1, gc = c+1;
            }
            if(gr >= 1 and gr <= R and gc >=1 and gc <= C and a[gr][gc] == '.' and !chk[gr][gc][t][cd]){
                chk[gr][gc][t][cd] = true;
                qq.emplace(gr, gc, cd);
            }
        }
    }

    for(int i=1; i<=R; i++) for(int j=1; j<=C; j++) for(int t=0; t<4; t++) for(int k=0; k<4; k++) ok[i][j][t] |= chk[i][j][t][k];

    if(DEBUG){
        for(int t=0; t<4; t++){
            for(int i=1; i<=R; i++){
                for(int j=1; j<=C; j++){
                    cout << ok[i][j][t] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }

    pq.emplace(0, str, stc, 0);
    dis[str][stc][0] = 0;
    while(!pq.empty()){
        auto [wa, r, c, t] = pq.top();
        pq.pop();

        if(DEBUG){
            cout << r << " " << c << " " << t << " " << dis[r][c][t%4] << "\n";
        }

        for(int i=0; i<4; i++){
            int gr = r+pr[i], gc = c+pc[i];
            if(gr < 1 or gr > R or gc < 1 or gc > C) continue;
            if(ok[gr][gc][(t+1)%4]) continue;
            if(a[gr][gc] != '.' and a[gr][gc] != 'E') continue;
            if(dis[r][c][t%4]+1 < dis[gr][gc][(t+1)%4]){
                dis[gr][gc][(t+1)%4] = dis[r][c][t%4]+1;
                pq.emplace(dis[gr][gc][(t+1)%4], gr, gc, t+1);
            }
        }
    }

    int ans = 1e9;
    for(int i=0; i<4; i++)
        ans = min(ans, dis[edr][edc][i]);
    if(ans == 1e9)
        ans = -1;
    cout << ans;
    /*for(auto [r,c,cd] : saber){
        cout << r << " " << c << " " << cd << "\n";
    }*/
}
