#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 1e3+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;
///http://www.usaco.org/index.php?page=viewproblem2&cpid=895
int n,mnp,mxs,gr[]={-1,1,0,0},gc[]={0,0,-1,1};
char a[N][N];
bool vi[N][N];

void setIO(string name=""){
    ios_base::sync_with_stdio(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void bfs(int ssr, int ssc){
    queue<pi> qq;
    qq.emplace(ssr, ssc);
    int sz = 0, pr = 0;
    while(!qq.empty()){
        auto [nr, nc] = qq.front();
        qq.pop();
        vi[nr][nc] = true;
        int cou = 4;
        sz++;
        for(int i=0; i<4; i++){
            int r = nr+gr[i], c = nc+gc[i];
            if(!vi[r][c] and a[r][c] == '#'){
                qq.emplace(r, c);
                vi[r][c] = true;
            }
            if(a[r][c] == '#'){
                cou--;
            }
        }
        pr += cou;
    }
    if(sz > mxs){
        mxs = sz;
        mnp = pr;
    }else if(sz == mxs){
        mnp = min(mnp, pr);
    }
    return;
}

main(){
    setIO("perimeter");
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j] == '#' and !vi[i][j]){
                bfs(i, j);
            }
        }
    }
    cout << mxs << " " << mnp << "\n";
}

