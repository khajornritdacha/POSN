#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,maxx;
long long ans,sum;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        a[x]++;
        a[y]--;
        maxx = max(maxx,y);
    }
    for(int i=0;i<=maxx+1;i++){
        //cout << a[i] << " ";
        sum+=a[i];
        ans = max(sum,ans);
    }
    //cout << "\n";
    cout << ans;
}
