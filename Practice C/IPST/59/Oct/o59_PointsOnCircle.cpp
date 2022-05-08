#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,K,a[N][N],ans[N];
main(){
    cin >> n >> K;
    for(int i=1; i<=K; i++){
        for(int j=1; j<=K; j++){
            cin >> a[i][j];
        }
    }
    if(K == 1){
        cout << 0;
        return 0;
    }
    ans[1] = 0;
    ans[2] = a[1][2];
    for(int i=3; i<=K; i++){
        int x1 = a[1][i];
        int x2 = n-a[1][i];
        int y1 = a[2][i]+ans[2];
        int y2 = ((ans[2]-a[2][i])%n+n)%n;
        if(x1 == y1 or x1 == y2){
            ans[i] = x1;
        }else{
            ans[i] = x2;
        }
    }
    for(int i=1; i<=K; i++){
        cout << ans[i] << "\n";
    }
}
