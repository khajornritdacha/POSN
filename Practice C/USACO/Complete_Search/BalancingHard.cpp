#include<bits/stdc++.h>
using namespace std;
int n,ans=2e9;
vector<pair<int,int>> vec;

main(){
    freopen("balancing.in","r",stdin);
    freopen("balancing.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        vec.emplace_back(x,y);
    }
    sort(vec.begin(),vec.end());
    for(int i=0; i<n; i++){
        int hori=vec[i].second+1;
        int bl,br,tl,tr;
        bl=br=tl=tr=0;
        for(int j=0; j<n; j++){
            if(vec[j].second<hori)
                br++;
            else
                tr++;
        }
        for(int j=0; j<n; j++){
            if(vec[j].second<hori){
                bl++;
                br--;
            }else{
                tl++;
                tr--;
            }
            ans=min(ans,max({bl,br,tl,tr}));
        }
    }
    cout << ans;
}
