#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
vector<pi> vec;
ll ans,trn[100005],trqs[100005];
int n;
void upn(int i,int v){
    while(i<=n){
        trn[i]+=v;
        i+=(i&-i);
    }
}
void upqs(int i,int v){
    while(i<=n){
        trqs[i]+=v;
        i+=(i&-i);
    }
}
ll sumn(int i){
    ll su=0;
    while(i>0){
        su+=trn[i];
        i-=(i&-i);
    }
    return su;
}
ll qs(int i){
    ll su=0;
    while(i>0){
        su+=trqs[i];
        i-=(i&-i);
    }
    return su;
}
main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        vec.emplace_back(x,y);
    }
    sort(vec.rbegin(),vec.rend());
    for(int i=0;i<n;i++){
        //cout << sumn(vec[i].second) << " " << vec[i].first << " " << qs(vec[i].second) << "\n";
        ans+=(sumn(vec[i].second)*vec[i].first)+qs(vec[i].second);
        upn(vec[i].second,1);
        upqs(vec[i].second,vec[i].first);
    }
    cout << ans;
}
