#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y,K,ans,now,la;
main(){
    cin >> x >> y >> K;
    int di = 5;
    while(x/di){
        la = (x/di)+la;
        di*=5;
    }
    ans += la;
    //cout << la << "\n";
    for(int i=x+1; i<=y; i++){
        int cnt = 0, ne = 0, tmp = i;
        di = 5;
        while(i%di == 0){
            ne++, di*=5;
        }
        now = (la + ne)%K;
        //cout << "I : " << i << " = " << ne << " " << now << " " << la << "\n";
        ans = (ans+now)%K;
        la = now;
    }
    cout << ans << "\n";
}
