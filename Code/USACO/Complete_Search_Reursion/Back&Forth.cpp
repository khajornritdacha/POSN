#include<bits/stdc++.h>
using namespace std;

const int N = 2e3+10;
int n,val[2],ans;
bool chk[N];
vector<pair<int,int>> vec;

void setIO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

void solve(int lv = 0){
    if(lv == 4){
        if(!chk[val[0]]){
            ans++;
            chk[val[0]] = true;
        }
        return;
    }

    int now = lv%2;
    for(auto &[sz, cur] : vec){
        if(cur == now){
            val[now] -= sz;
            val[!now] += sz;
            cur = !now;
            solve(lv+1);
            cur = now;
            val[now] += sz;
            val[!now] -= sz;
        }
    }

}
main(){
    setIO("backforth");
    for(int i=0; i<2; i++){
        for(int j=0; j<10; j++){
            int x;
            cin >> x;
            vec.emplace_back(x, i);
        }
    }
    val[0] = val[1] = 1000;
    solve();

    cout << ans;
}

