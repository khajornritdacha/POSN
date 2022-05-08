#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
long long m,n,ans[N][N];
main(){
    cin >> m >> n;
    for(int t=0; t<2; t++) for(int i=1; i<=m; i++)for(int j=1; j<=n; j++){
        int x;
        cin >> x;
        ans[i][j]+=x;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            cout << ans[i][j] << " \n"[j==n];
        }
    }
}
