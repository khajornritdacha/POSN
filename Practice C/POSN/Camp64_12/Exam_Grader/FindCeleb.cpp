#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
int a[N][N],n,ans=-1;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(i == j) continue;
            cin >> a[i][j];
            if(a[i][j] == 0)
                cnt++;
        }
        if(cnt == n-1){
            if(ans == -1)
                ans = i;
            else
                ans = 0;
        }
    }
    cout << ans;
}
