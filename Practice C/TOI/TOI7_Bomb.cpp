#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[1000005];
bool chk[1000005];
int n,maxx=1e9;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        a[i] = {x,-y};
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        if(a[i].second<=maxx){
            maxx = a[i].second;
            chk[i] = true;
        }
    }
    for(int i=0;i<n;i++){
        if(chk[i])
            cout << a[i].first << " " << -a[i].second << "\n";
            //printf("%d %d\n",a[i].first,-a[i].second);
            //vec.emplace_back(a[i].first,-a[i].second);
    }
    /*sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        printf("%d %d\n",vec[i].first,vec[i].second);
    }*/
}
