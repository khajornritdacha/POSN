#include<bits/stdc++.h>
using namespace std;
long long minn=1e17;
int n;
vector<long long> a,b;
vector<pair<long long,long long>> vec;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.emplace_back(x);
        minn = min(a[i],minn);
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        b.emplace_back(x);
    }
    for(int i=0;i<n;i++){
        vec.emplace_back(b[i],a[i]);
    }
    sort(vec.begin(),vec.end());
    long long temp=0,pos = vec[0].first,h=0,ans;
    for(int i=1;i<n;i++){
        temp+=(vec[i].first-vec[0].first);
    }
    ans = temp;
    for(int i=1;i<n;i++){
        if(vec[i].first>minn)
            break;
        h+=vec[i-1].first+vec[i-1].second-vec[i].first;
        if(vec[i-1].first==vec[i].first)
            continue;
        temp-=(vec.size()-1)*(vec[i].first-vec[i-1].first);
        temp+=h;
        h=0;
        if(temp<ans){
            ans = temp;
            pos = vec[i].first;
        }
    }
    cout << pos << " " << ans;
}
