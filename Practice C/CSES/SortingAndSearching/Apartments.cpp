#include <bits/stdc++.h>
using namespace std;


int main(void){
    int n,m,K;
    cin >> n >> m >> K;
    int a[n+5] = {} , b[m+5] = {};
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= m; i++){
        cin >> b[i];
    }
    sort(b+1, b+m+1);

    int ans = 0;
    for(int i = 1, j = 1; i <= n; i++){
        while(j < m and a[i]-K > b[j]){
            j++;
        }
        if(j <= m and abs(b[j]-a[i]) <= K){
            ans++;
            j++;
        }
    }
    cout << ans << "\n";
    return 0;
}
