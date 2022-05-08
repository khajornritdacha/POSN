#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,a[N][N],cnt;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        a[x][y]++;
    }
    for(int i=0; i<=1e3; i++){
        for(int j=0; j<=1e3; j++){
            cnt += (a[i][j] != 0);
        }
    }
    cout << cnt;
}
