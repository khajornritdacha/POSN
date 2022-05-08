#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,K,qs[N],ans;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        if(str == "UR")
            qs[i]++;
        qs[i]+=qs[i-1];
    }
    for(int i=K; i<=n; i++){
        ans = max(ans, qs[i]-qs[i-K]);
    }
    cout << ans << "\n";
}
