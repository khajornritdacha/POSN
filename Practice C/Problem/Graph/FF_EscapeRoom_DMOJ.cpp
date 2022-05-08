#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;

int m,n,a[N][N];
queue<int> qq;
bool vi[N*N];
vector<int> vec[N*N];
///https://dmoj.ca/problem/ccc20s2

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            vec[i*j].emplace_back(a[i][j]);
        }
    }
    qq.emplace(1);
    while(!qq.empty()){
        int u = qq.front();
        qq.pop();
        vi[u] = true;
        if(u == n*m)
            break;
        for(int v : vec[u]){
            if(!vi[v]){
                vi[v] = true;
                qq.emplace(v);
            }
        }

    }
    cout << (vi[m*n] ? "yes" : "no");
}


