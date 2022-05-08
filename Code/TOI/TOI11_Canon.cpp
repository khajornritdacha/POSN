#include<bits/stdc++.h>
using namespace std;
int n,m,k,l;
vector<int> vec;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m >> k >> l;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        vec.emplace_back(x);
        //cout << vec[i] << " ";
    }
    //cout << lower_bound(vec.begin(),vec.end(),200)-vec.begin();
    while(k--){
        vector<int> pl;
        for(int i=0;i<m;i++){
            int x;
            cin >> x;
            pl.emplace_back(x);
        }
        int st=0,ed=0,tst,ted,ans=0;
        for(int i=0;i<m;i++){
            //cout << pl[i] << " " << pl[i]-l << " " << pl[i]+l << "\n";
            tst = lower_bound(vec.begin(),vec.end(),pl[i]-l)-vec.begin();
            ted = upper_bound(vec.begin(),vec.end(),pl[i]+l)-vec.begin();
            if(tst<ed){
                tst = ed;
            }
            //cout << tst << " " << ted << "\n";
            ans+=ted-tst;
            st = tst;
            ed = ted;
        }
        cout << ans << "\n";
    }
}
