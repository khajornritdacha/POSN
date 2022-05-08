#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
int n,q,t;
long long K,qs[100010];
vector<long long> vec;
set<long long> ss;
void solve(int l, int r){
    if(DEBUG){
        cout << l << " " << r << " " << qs[r]-qs[l-1] << "\n";
    }
    ss.insert(qs[r]-qs[l-1]);
    if(l==r)
        return;
    if(vec[l]==vec[r])
        return;
    long long mid=(vec[l]+vec[r])/2;
    int pos=upper_bound(vec.begin(),vec.end(),mid)-vec.begin();
    if(DEBUG){
        cout << "Mid&Pos: " << mid << " " << pos << "\n";
    }
    solve(l,pos-1);
    solve(pos,r);
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        long long sum=0;
        cin >> n >> q;
        vec.emplace_back(0);
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            vec.emplace_back(x);
            sum+=x;
        }
        sort(vec.begin(),vec.end());
        for(int i=1; i<=n; i++){
            qs[i]=qs[i-1]+vec[i];
        }
        solve(1,n);
        for(int i=0; i<q; i++){
            cin >> K;
            if(DEBUG){
                cout << "Case : " << i+1 << "\n";
            }
            if(ss.find(K)!=ss.end())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        vec.clear();
        fill(qs,qs+n+1,0);
        ss.clear();
    }
}
