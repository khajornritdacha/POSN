#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
const int mxn = 5e5+10;
ll decre,now,sumh[mxn],ans=1e18,mn=1e18,idx,qs[mxn];
int h[mxn],p[mxn],lastdif,N;
vector<pair<int,int>> vec;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> h[i];
        mn = min(mn, h[i]);
    }
    for(int i=1; i<=N; i++){
        cin >> p[i];
        vec.emplace_back(p[i], h[i]);
    }
    vec.emplace_back(0,0);
    vec.emplace_back(2e9,2e9);
    sort(vec.begin(), vec.end());
    for(int i=1; i<=N; i++){
        qs[i] = qs[i-1]+vec[i].first;
        sumh[i] = sumh[i-1]+vec[i].second;
    }
    ll np,nh;
    for(int i=1; i<=N; i++){
        tie(np, nh) = vec[i];
        if(np > mn)
            break;
        if(vec[i].first != vec[i+1].first){
            decre += (lastdif)*(vec[i].first-vec[lastdif].first);
            now = sumh[lastdif]-decre+qs[N]-qs[i]-((N-i)*vec[i].first);
            //cout << now << " ";
            if(now < ans){
                ans = now;
                idx = i;
            }
            lastdif = i;
        }
    }
    cout << vec[idx].first << " " << ans << "\n";
}
