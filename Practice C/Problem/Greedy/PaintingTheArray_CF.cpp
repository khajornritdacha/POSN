#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,nex[N],a[N],pos[N],ans;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        pos[i] = 1e9;
    }
    pos[0] = 1e9;
    for(int i=n; i>=0; i--){
        nex[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    int x=0,y=0;
    for(int i=1; i<=n; i++){
        if(a[i] == a[x]){
            ans += (a[y]!=a[i]);
            y = i;
        }else if(a[i] == a[y]){
            ans += (a[x]!=a[i]);
            x = i;
        }else if(nex[x] < nex[y]){
            ans += (a[x]!=a[i]);
            x = i;
        }else{
            ans += (a[y]!=a[i]);
            y = i;
        }
    }
    cout << ans << "\n";
}
///https://codeforces.com/contest/1479/problem/B1
