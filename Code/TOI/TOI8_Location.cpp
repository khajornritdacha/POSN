#include<bits/stdc++.h>
using namespace std;
long long a[1005][1005],r,c,k,sum[1005][1005],maxx=0;
main(){
    cin >> r >> c >> k;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    for(int i=k;i<=r;i++){
        for(int j=k;j<=c;j++){
            long long now = sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k];
            maxx = max(maxx,now);
        }
    }
    cout << maxx;
}

