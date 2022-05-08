#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n,a[N][N],m,K;
main(){
    cin >> n >> m >> K;
    for(int i=1; i<=K; i++){
        int r,c;
        cin >> r >> c;
        a[r][c] = i;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
