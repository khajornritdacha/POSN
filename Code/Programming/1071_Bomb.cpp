#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+100;
int n,m,a[N][N];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        a[y][x]++;
    }
    for(int t=1; t<=m; t++){
        int x,y,r;
        int cnt = 0;
        cin >> x >> y >> r;
        for(int i=max(0,y-r); i<=min(1000,y+r); i++){
            for(int j=max(0,x-r); j<=min(1000,x+r); j++){
                if(a[i][j]){
                    cnt++;
                    a[i][j] = 0;
                }
            }
        }
        cout << cnt << "\n";
    }
}
