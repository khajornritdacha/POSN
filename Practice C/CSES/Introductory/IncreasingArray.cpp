#include <bits/stdc++.h>
using namespace std;


int main(void){
    long long n,pre,now,ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> now;
        if(i > 1){
            if(pre > now){
                ans +=  pre-now;
                now = pre;
            }
        }
        pre = now;
    }
    cout << ans << "\n";
    return 0;
}
