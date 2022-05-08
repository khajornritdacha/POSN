#include<bits/stdc++.h>
using namespace std;


void solve(){
    int M,n,cnt=0;
    cin >> M >> n;
    for(int i=0; i<=M; i++){
        if((n-i)%20 == 0){
            int tmp = (n-i)/20;
            if(tmp >= 0 and tmp*20+i == n){
                //cout << i << " " << tmp << " " << tmp*20 << "\n";
                cnt++;
            }
        }
    }
    cout << cnt;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    for(int i=1; i<=T; i++){
        cout << "Case #"<<i<<": ";
        solve();
        cout << "\n";
    }
}
