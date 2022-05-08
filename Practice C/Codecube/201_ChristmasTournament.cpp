#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        bool ok = true;
        int cnt[5] = {};
        cin >> cnt[0] >> cnt[1] >> cnt[2];
        if(cnt[0] > 1 and cnt[2] <= 0){
            ok = false;
        }
        if(cnt[1] > 1 and cnt[0] <= 0){
            ok = false;
        }
        if(cnt[2] > 1 and cnt[1] <= 0){
            ok = false;
        }
        if(ok){
            cout << "YES";
        }else{
            cout << "NO";
        }
        cout << "\n";
    }
}
