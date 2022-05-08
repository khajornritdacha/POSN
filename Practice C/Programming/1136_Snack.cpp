#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n[5],a[5][N],ans;
long long sum[5];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n[0] >> n[1];
    for(int t=0; t<2; t++){
        for(int i=1; i<=n[t]; i++){
            cin >> a[t][i];
            sum[t]+=a[t][i];
        }
    }
    for(int t=0; t<2; t++){
        int cur = t%2, cnt = 0;
        int sz[5] = {n[0], n[1]};
        long long stmp[5] = {sum[0], sum[1]};
        for(int i=1; i<=n[t]; i++){
            if(a[cur][i] > stmp[!cur]/sz[!cur] and 1ll*a[cur][i]*sz[cur] < stmp[cur]){
                sz[cur]--;
                sz[!cur]++;
                stmp[cur]-=a[cur][i];
                stmp[!cur]+=a[cur][i];
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}
