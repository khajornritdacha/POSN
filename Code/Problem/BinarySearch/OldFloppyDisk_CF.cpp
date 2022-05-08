#include<bits/stdc++.h>
#define int long long
using namespace std;
using pi = pair<int,int>;
const int mxn = 2e5+10;
vector<pi> vec;
int a[mxn],qs[mxn],t,sum,mx,n,m;
int bi(int val){
    int l=0, r=vec.size()-1, mid,ans=vec.size()-1;
    while(l<=r){
        mid = (l+r)/2;
        if(vec[mid].first>=val){
            ans = min(ans, mid);
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    //cout << "VAL : " << val << " " << vec[ans].first << " " << vec[ans].second << "\n";
    return vec[ans].second;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        sum = mx = 0;
        vec.clear();
        cin >> n >> m;
        vec.emplace_back(0,0);
        for(int i=1; i<=n; i++){
            cin >> a[i];
            qs[i] = qs[i-1]+a[i];
            if(qs[i] > vec.back().first){
                vec.emplace_back(qs[i], i);
            }
            mx = max(mx, qs[i]);
            sum+=a[i];
        }
        for(int i=1; i<=m; i++){
            int x;
            cin >> x;
            if(sum <= 0 || x<=mx){
                if(x<=mx){
                    int k = bi(x);
                    cout << k-1 << " ";
                }else{
                    cout << "-1 ";
                }
                continue;
            }
            int full = (x-mx+sum-1)/sum;
            //cout << "FULL : " << x << " " << full << "\n";
            int k = bi(x-(full*sum));
            cout << k+(n*full)-1 << " ";
        }
        cout << "\n";
    }
}
