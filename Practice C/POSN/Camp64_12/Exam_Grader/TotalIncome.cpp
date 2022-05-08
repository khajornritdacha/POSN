#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x >= 8){
            ans += min(4,x-8)*50;
            ans += 300;
            cnt = 0;
        }else if(x >= 4){
            ans += 150;
            cnt = 0;
        }else{
            cnt++;
        }
        if(cnt >= 3)
            break;
    }
    cout << ans;
}
