#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n,m,K,a[N][N];

main(){
    cin >> n >> m >> K;
    for(int i=1; i<=K; i++){
        int x,y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == 0)
                cout << "_";
            else
                cout << "x";
        }
        cout << "\n";
    }
}
