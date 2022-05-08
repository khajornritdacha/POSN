#include<bits/stdc++.h>
using namespace std;
int n,k,m,bound,ans;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> m;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x>bound){
            bound=x+m;
            ans++;
        }
    }
    cout << ans;
}
