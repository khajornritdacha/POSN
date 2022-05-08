#include<bits/stdc++.h>
using namespace std;
int n,t[1010][1010],mx;
long long ans;
set<int> ss;
vector<pair<int,int>> vec;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int a;
            cin >> a;
            t[i][j]=max(t[i-1][j],t[i][j-1])+1;
            if(i==1&&j==1) t[i][j]=0;
            mx=max(mx,t[i][j]);
            vec.emplace_back(a,t[i][j]);
            //cout << t[i][j] << " ";
        }
        //cout << "\n";
    }
    for(int i=1; i<=mx; i++) ss.insert(i);
    sort(vec.rbegin(),vec.rend());
    for(auto [cost,time]:vec){
        auto it = ss.upper_bound(time);
        if(it==ss.begin()) continue;
        it--;
        ans+=cost;
        ss.erase(it);
    }
    cout << ans;
}
