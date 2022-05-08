#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n,m,a[N][N],ra[N],b[N][N],ca[N],rb[N],cb[N],ans,sum;
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++){
        cin >> a[i][j];
        ra[i]+=a[i][j];
        ca[j]+=a[i][j];
        sum+=a[i][j];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> b[i][j];
            rb[i]+=b[i][j];
            cb[j]+=b[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        ans = max(ans, sum-ra[i]+rb[i+1]+rb[i-1]);
    }
    for(int j=1; j<=m; j++){
        ans = max(ans, sum-ca[j]+cb[j-1]+cb[j+1]);
    }
    cout << ans << "\n";
}
