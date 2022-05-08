#include<bits/stdc++.h>
using namespace std;
using tu=tuple<int,int,int>;
int n,ans;
vector<tu> vec;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y,r;
        cin >> x >> y >> r;
        vec.emplace_back(x,y,r);
    }
    sort(vec.begin(),vec.end());
    for(int i=0; i<n; i++){
        auto [x1,y1,r1] = vec[i];
        for(int j=i+1; j<n; j++){
            auto [x2,y2,r2] = vec[j];
            if(abs(x1-x2) > 20)
                break;
            if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) < (r1+r2)*(r1+r2))
                ans++;
        }
    }
    cout << ans;
}
