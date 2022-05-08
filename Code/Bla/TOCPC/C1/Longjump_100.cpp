#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 1e6+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;

int n,m,W,sx,sy,ex,ey;
set<int> wix[N],wiy[N];
set<pi> vi;
queue<tu> qq;

void go(const int &dis, const int &x, const int &y){
    if(!vi.count({x, y})){
        vi.insert({x, y});
        qq.emplace(dis, x, y);
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> W >> sx >> sy >> ex >> ey;

    for(int i = 1; i <= W; i++){
        int x, y; cin >> x >> y;
        wix[x].insert(y);
        wiy[y].insert(x);
    }

    vi.insert({ex, ey});
    qq.emplace(0, ex, ey);
    while(!qq.empty()){
        auto [dis, nx, ny] = qq.front(); qq.pop();

        //cout << dis << " " << nx << " " << ny << "\n";

        if(nx == sx and ny == sy){
            cout << dis << "\n";
            return 0;
        }

        auto iv = wix[nx].upper_bound(ny);
        auto ih = wiy[ny].upper_bound(nx);

        int gx = nx, gy;
        if(iv == wix[nx].end()) gy = m; //its up is wall
        else gy = (*iv)-1;
        go(dis+1, gx, gy);

        if(iv  == wix[nx].begin()) gy = 1; //its down is wall
        else gy = (*(--iv))+1;
        go(dis+1, gx, gy);

        gy = ny;
        if(ih == wiy[ny].end()) gx = n; //its right is wall
        else gx = (*ih)-1;
        go(dis+1, gx, gy);

        if(ih == wiy[ny].begin()) gx = 1; //its left is wall
        else gx = (*(--ih))+1;
        go(dis+1, gx, gy);
    }

    cout << "-1\n"; 
    return 0;
}