#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500100],ans;
vector<pair<int,int>> vec;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    vec.emplace_back(a[1],1);
    for(int i=2; i<=n; i++){
        int dup=1;
        while(!vec.empty()&&a[i]>=vec.back().first){
            if(a[i]==vec.back().first){
                dup+=vec.back().second;
            }
            ans+=vec.back().second;
            vec.pop_back();
        }
        if(!vec.empty())
            ans++;
        vec.emplace_back(a[i],dup);
    }
    cout << ans;
}
