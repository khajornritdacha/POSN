#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int a,b,n,w[N],mn=1e9,ans;
main(){
    cin >> n >> a >> b;
    for(int i=1; i<=n; i++){
        cin >> w[i];
    }
    for(int i=a; i<=b; i++){
        int now = 0, res = 0;
        bool ok = true;
        for(int j=1; j<=n; j++){
            if(w[j] > i){
                ok = false;
                break;
            }
            if(w[j]+now > i){
                res += i-now;
                now = 0;
            }
            now+=w[j];
        }
        res += i-now;
        if(ok and res < mn){
            mn = res;
            ans = i;
        }
    }
    cout << ans;
}
