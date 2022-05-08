#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+10;
using pi = pair<int,int>;
int n,Q,mul[N];
vector<pi> vec;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=0; i<n; i++){
        int l,r,x;
        cin >> l >> r >> x;
        vec.emplace_back(l, r);
        if(x == 1)
            mul[i] = -1;
        else
            mul[i] = 1;
    }
    while(Q--){
        int t;
        cin >> t;
        int cnt = n;
        vector<pi> now;
        for(int i=0; i<n; i++){
            if(mul[i] == -1){
                if(vec[i].second+mul[i]*t >= 1)
                    now.emplace_back(vec[i].first+mul[i]*t, vec[i].second+mul[i]*t);
                else
                    cnt--;
            }else{
                if(vec[i].first+mul[i]*t <= 1e9)
                    now.emplace_back(vec[i].first+mul[i]*t, vec[i].second+mul[i]*t);
                else
                    cnt--;

            }
        }
        sort(now.begin(), now.end());
        for(int i=0; i+1<now.size(); i++){
            if(now[i].second >= now[i+1].first){
                cnt--;
                now[i+1].second = max(now[i].second, now[i+1].second);
            }
        }
        cout << cnt << "\n";
    }
}
