#include<bits/stdc++.h>
using namespace std;
int n,k;
long long now,a[100100],ans;
vector<long long> expo;
map<long long, long long> ump;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    now=k;
    if(k!=1&&k!=-1){
        expo.emplace_back(1);
        expo.emplace_back(now);
        for(; abs(now)<1e14; ){
            now*=k;
            expo.emplace_back(now);
        }
    }else{
        if(k==1)
            expo.emplace_back(k);
        else{
            expo.emplace_back(-1);
            expo.emplace_back(1);
        }
    }
    now=0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        now+=a[i];
        ump[now]++;
        //cout << now << " ";
    }
    now=0;
    for(int i=0; i<=n; i++){
        now+=a[i];
        //cout << "I: " << i << " " << now << "\n";
        for(auto x:expo){
            //cout << x << " " << x+now << " " << ump.count(x+now) << "\n";
            if(ump.find(x+now)!=ump.end())
                ans+=ump[x+now];
        }
        if(i!=0){
            if(--ump[now]==0)
                ump.erase(now);
        }
    }
    cout << ans;
}
