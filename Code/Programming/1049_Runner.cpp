#include<bits/stdc++.h>
using namespace std;
int n,m,limit,maxx[100005],ans[100005],ru[100005];
unordered_map<int,int> mp;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        int temp = mp[y];
        if(z>maxx[temp]){
            maxx[temp] = z;
            ans[temp] = x;
            ru[temp] = y;
        }else if(z==maxx[temp]&&y<ru[temp]){
            ans[temp] = x;
        }
        mp[y]++;
        limit = max(limit,temp+1);
    }
    for(int i=0;i<limit;i++)
        cout << ans[i] << "\n";
}
