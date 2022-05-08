#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
int n,m,a[N],b[N],mn=1e9;

main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=m; i++){
        cin >> b[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            mn = min(mn, a[i]+a[j]);
        }
    }

    for(int i=1; i<=m; i++){
        for(int j=i+1; j<=m; j++){
            mn = min(mn, b[i]+b[j]);
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            mn = min(mn, a[i]+b[j]+100);
        }
    }

    cout << mn;
}
