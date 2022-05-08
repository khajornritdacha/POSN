#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+100;
int n,a[N],b[N],c[N];
void TC(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> c[i];
    }
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> b[i];
    }
    int last = abs(b[2]-a[2])+1,ans=0;
    for(int i=2; i<=n; i++){
        if(a[i] == b[i])
            last = 1;
        ans = max(ans, last+c[i]);
        last = max(last+c[i]-abs(b[i+1]-a[i+1])+1, abs(b[i+1]-a[i+1])+1);
        //cout << "IDX : " << i << " " << last << "\n";
    }
    cout << ans << "\n";
    return;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        TC();
    }
}
///https://codeforces.com/problemset/problem/1476/C
