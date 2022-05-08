#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
struct DATA{
    int xo,xe,yo,ye;
};
DATA a[N];
int n,m;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i].xo >> a[i].yo >> a[i].xe >> a[i].ye;
    }
    while(m--){
        int jlx,jly,jrx,jry;
        cin >> jlx >> jly >> jrx >> jry;
        int xs,ys,xp,yp,ans=0;
        for(int i=1; i<=n; i++){
            xs = max(a[i].xo, jlx);
            ys = min(a[i].yo, jly);
            xp = min(a[i].xe, jrx);
            yp = max(a[i].ye, jry);
            if(max(0,xp-xs)*max(0,ys-yp) > 0)
                ans++;
        }
        cout << ans << "\n";
    }
}
