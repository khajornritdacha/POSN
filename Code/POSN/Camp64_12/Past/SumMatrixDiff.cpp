#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n,a[N][N],ans;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            ans += abs(a[i][j]-a[j][i]);
        }
    }
    cout << ans;
}
