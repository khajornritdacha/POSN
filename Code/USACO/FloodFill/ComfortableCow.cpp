#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 1e3+10;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

queue<pi> qq;
int n,T=1001,cnt,px[]={-1,1,0,0},py[]={0,0,-1,1};
bool a[2*N][2*N];
///http://www.usaco.org/index.php?page=viewproblem2&cpid=1110
void bfs(){
    while(!qq.empty()){
        auto [nx, ny] = qq.front();
        qq.pop();
        int cou = 0, gx, gy;
        for(int i=0; i<4; i++){
            if(a[T+nx+px[i]][T+ny+py[i]]){
                cou++;
            }else{
                gx = nx+px[i], gy = ny+py[i];
            }
        }
        if(cou == 3){
            a[T+gx][T+gy] = 1;
            cnt++;
            qq.emplace(gx, gy);
            for(int i=0; i<4; i++){
                if(a[T+gx+px[i]][T+gy+py[i]])
                    qq.emplace(gx+px[i], gy+py[i]);
            }
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); //freopen("countcross.in", "r", stdin); freopen("countcross.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        if(a[T+x][T+y]){
            cnt--;
        }
        a[T+x][T+y] = 1;
        qq.emplace(x, y);
        for(int i=0; i<4; i++){
            if(a[x+px[i]+T][y+py[i]+T])
                qq.emplace(x+px[i], y+py[i]);
        }
        bfs();
        cout << cnt << "\n";
    }
}
