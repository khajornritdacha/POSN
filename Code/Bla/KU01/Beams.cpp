#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using ll = long long;

int n,m,a[N],b[N];

int main(void){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int j = 1; j <= m; j++){
        cin >> b[j];
    }
    int ans = 1, cur[2] = {}, pre[2] = {};
    for(int i = 1, j = 1; i <= n; i++, cur[0] = !cur[0]){
        while(j <= m and a[i] > b[j]){
            ans += (a[i-1] < b[j-1] or cur[0] != cur[1]);
            j++, cur[1] = !cur[1];
        }
        if(j <= m and a[i] == b[j]){
            ans++;
            j++, cur[1] = !cur[1];
        }else if(j <= m and a[i] < b[j]){
            ans += (a[i-1] > b[j-1] or cur[0] != cur[1]);
        }
        //cout << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}
