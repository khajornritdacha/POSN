#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,a[1010],mx,ans;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(a[j] == a[i]){
                cnt++;
            }
        }
        if(cnt > mx){
            mx = cnt;
            ans = a[i];
        }else if(cnt == mx){
            ans = max(ans, a[i]);
        }
    }
    cout << ans << "\n" << mx << "\n";
}
