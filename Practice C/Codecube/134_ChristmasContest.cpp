#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
long long ans;
int n,a[N],m,b[N],num[40][2];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int j=1; j<=m; j++){
        cin >> b[j];
        for(int i=0; i<30; i++){
            if(b[j]&(1<<i)){
                num[i][1]++;
            }else{
                num[i][0]++;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int bit=0; bit<30; bit++){
            if(a[i]&(1<<bit)){
                ans += 1ll*num[bit][0]*(1<<bit);
            }else{
                ans += 1ll*num[bit][1]*(1<<bit);
            }
        }
    }

    cout << ans;
}
