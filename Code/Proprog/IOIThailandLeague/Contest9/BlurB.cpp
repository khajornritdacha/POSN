#include<bits/stdc++.h>
using namespace std;

const int N = 2e2+10;
int n,m,M,qs[N][N],a[N][N];

main(){
    cin >> n >> m >> M;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
            qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int ro = max(1, i-M/2);
            int co = max(1, j-M/2);
            int re = min(n, i+M/2);
            int ce = min(m, j+M/2);
            //cout << ro << " " << co << " " << re << " " << ce << " " << qs[re][ce] << "\n";
            cout << (qs[re][ce]-qs[re][co-1]-qs[ro-1][ce]+qs[ro-1][co-1])/((re-ro+1)*(ce-co+1)) << " ";
        }
        cout << "\n";
    }
}
