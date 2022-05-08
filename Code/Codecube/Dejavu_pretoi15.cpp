#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
ll ans;
int la=2e9,n;
vector<int> vec,pos[100005];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        int k=upper_bound(vec.begin(),vec.end(),x)-vec.begin();
        if(k==vec.size()){
            vec.push_back(x);
        }else{
            vec[k]=x;
        }
        pos[k].push_back(x);
    }
    cout << vec.size() << " ";
    for(int i=vec.size()-1;i>=0;i--){
        int now=0;
        for(auto j:pos[i]){
            if(j>=now&&j<=la){
                now=j;
            }
        }
        ans+=now;
        la=now;
    }
    cout << ans;
}
