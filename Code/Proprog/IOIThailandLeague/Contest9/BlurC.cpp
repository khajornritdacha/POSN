#include<bits/stdc++.h>
using namespace std;

const int N = 2e3+5;
int n,m,M,qs[N][N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //cout << sizeof(qs) << "\n";
    cin >> n >> m >> M;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int x;
            cin >> x;
            qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+x;
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
