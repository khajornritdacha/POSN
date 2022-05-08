#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 25;
int n,W,co[N],ans;
bool ok = true;
void solve(int lv, int now){
    if(now <= 0)
        ok = false;
    if(lv == 1){
        ans+=now;
        return;
    }
    int tmp = 2*now-co[lv]+1;
    if(tmp%2){
        solve(lv-1, tmp/2+1);
    }else{
        solve(lv-1, tmp/2);
    }
    solve(lv-1, tmp/2);
}
main(){
    cin >> n >> W;
    for(int i=2; i<=n; i++){
        cin >> co[i];
    }
    solve(n, W);
    if(!ok)
        cout << "-1\n";
    else
        cout << ans << "\n";
}
