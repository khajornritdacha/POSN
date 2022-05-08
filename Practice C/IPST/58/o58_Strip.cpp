#include<bits/stdc++.h>
using namespace std;
const int W = 2e5+100;
const int lim = 1e5+100;
using pi = pair<int,int>;
int n,m,K,res[W],fen[W];
vector<pi> ans[W],ep[W];
int sum(int idx){
    int tmp = 0;
    while(idx){
        tmp+=fen[idx];
        idx-=(idx&-idx);
    }
    return tmp;
}
void up(int idx, int val){
    while(idx <= lim){
        fen[idx]+=val;
        idx+=(idx&-idx);
    }
}
main(){
    cin >> n >> m >> K;
    for(int i=1; i<=n; i++){
        int xs,ys,xe,ye;
        cin >> xs >> ys >> xe >> ye;
        ys++,ye++;
        ep[xs].emplace_back(ys, 1);
        ep[xs].emplace_back(ye+1, -1);
        ep[xe+1].emplace_back(ys, -1);
        ep[xe+1].emplace_back(ye+1, 1);
    }
    for(int i=1; i<=m; i++){
        int xx,yy;
        cin >> xx >> yy;
        yy++;
        ans[xx].emplace_back(yy, i);
    }
    for(int i=0; i<=lim; i++){
        //cout << "NOW : " << i << "\n";
        for(auto [pos, val] : ep[i]){
            //cout << "EP : " << pos << " " << val << "\n";
            up(pos, val);
        }
        for(auto [pos, idx] : ans[i]){
            //cout << "ANS : " << idx << " " << pos << " " << sum(pos)  << "\n";
            res[idx] = sum(pos);
        }
    }
    for(int i=1; i<=m; i++){
        cout << res[i] << "\n";
    }
}
