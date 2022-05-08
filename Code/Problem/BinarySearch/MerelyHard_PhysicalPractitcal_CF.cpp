#include<bits/stdc++.h>
using namespace std;
int n,ans;
vector<int> vec;
main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    ans=n-1;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec.emplace_back(x);
    }
    sort(vec.begin(),vec.end());
    if(vec[0]*2>=vec.back()){ cout << 0; return 0; }
    for(int i=0; i<vec.size(); i++){
        int v = vec[i];
        int k = upper_bound(vec.begin(),vec.end(),2*v)-vec.begin();
        if(k-1==i)
            continue;
        ans=min(ans,n-k+i);
    }
    cout << ans;
}
/*
https://codeforces.com/contest/253/problem/B
*/
