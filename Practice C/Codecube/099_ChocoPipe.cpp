#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

using tu = tuple<int,int,int,int>;
const int N = 1e2+10;
int A,B,C,W,H,dis[N][N][6];
char a[N][N];
vector<int> pr,pc,from;
priority_queue<tu, vector<tu>, greater<tu>> pq;

main(){
    cin >> A >> B >> C >> W >> H;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<=H; i++) for(int j=0; j<=W; j++) for(int k=0; k<4; k++) dis[i][j][k] = 1e9;

    int cost[] = {A,B,B};
    dis[H][1][1] = (a[H][1] == 'X' ? C : 0);
    pq.emplace(dis[H][1][1], H, 1, 1);
    while(!pq.empty()){
        auto [wa, nr, nc, code] = pq.top();
        pq.pop();

        if(code == 0 or code == 2){
            pr = {-1, 0, 0};
            pc = {0, -1, 1};
            from = {0, 3, 1};
            if(code == 2){
                pr[0] = 1;
                from[0] = 2;
            }
        }else{
            pr = {0, -1, 1};
            pc = {1, 0, 0};
            from = {1, 0, 2};
            if(code == 3){
                pc[0] = -1;
                from[0] = 3;
            }
        }

        for(int i=0; i<3; i++){
            int gr = nr+pr[i], gc = nc+pc[i];
            if(gr < 1 or gr > H or gc < 1 or gc > W) continue;
            if(dis[nr][nc][code]+cost[i]+(a[gr][gc] == 'X' ? C : 0) < dis[gr][gc][from[i]]){
                dis[gr][gc][from[i]] = dis[nr][nc][code]+cost[i]+(a[gr][gsc] == 'X' ? C : 0);
                pq.emplace(dis[gr][gc][from[i]], gr, gc, from[i]);
            }
        }
    }

    if(DEBUG){
        for(int k=0; k<4; k++){
            cout << "K : " << k << "\n";
            for(int i=1; i<=H; i++){
                for(int j=1; j<=W; j++){
                    cout << dis[i][j][k] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }

    cout << min(dis[1][W][0]+B, dis[1][W][1]+A);
}
