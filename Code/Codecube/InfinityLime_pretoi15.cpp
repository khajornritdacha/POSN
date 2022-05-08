#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
int m,k;
vector<pair<ll,ll>> kid;
vector<ll> vec;
int bi(int);
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> k;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    ll chua=0;
    kid.emplace_back(vec[0]-1,0);
    chua+=vec[0]-1;
    for(int i=0;i<vec.size()-1;i++){
        if(vec[i+1]-vec[i]>1){
            kid.emplace_back(vec[i+1]-vec[i]+chua-1,i+1);
            chua+=vec[i+1]-vec[i]-1;
        }
    }
    kid.emplace_back(2e9,vec.size());
    /*for(auto x:kid){
        cout << x.first << " " << x.second << "\n";
    }*/
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        if(x<vec[0])
            cout << x;
        else{
            int k=bi(x);
            cout << x+kid[k].second;
        }
        cout << " ";
    }
}
int bi(int i){
    int l=0,r=kid.size()-1,mid,ans=2e9;
    while(l<=r){
        mid = (l+r)/2;
        if(kid[mid].first>=i){
            ans=min(ans,mid);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}

