#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
const int N = 1e2+10;
long long n,m,L,K,C,ans;
main(){
    cin >> n >> m >> L >> K >> C;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        int x;
        cin >> x;
        ans+=x;
    }
    cout << (ans+L*K*C+C-1)/C;
}
