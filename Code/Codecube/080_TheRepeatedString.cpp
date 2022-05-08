#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
char str[N];

void solve(){
    cin >> str+1;
    int n = strlen(str+1),ans = 0;
    vector<bool> chk(n+5, false);

    for(int sz=1; sz<=n; sz++){
        if(n%sz != 0) continue;
        if(chk[sz]) continue;
        long long tmp = 0;
        bool ok = true;
        unordered_map<long long, int> mp;

        for(int i=1; i<=n; i++){
            tmp*=31;
            tmp += str[i];
            if(i%sz == 0){
                mp[tmp]++;
                tmp = 0;
            }
            if(mp.size() > 1){
                ok = false;
                break;
            }
        }

        if(ok){
            for(int i=sz; i<=n; i+=sz){
                if(n%i == 0){
                    ans++;
                    chk[i] = true;
                }
            }
        }
    }

    cout << ans << "\n";
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T = 5;
    while(T--){
        solve();
    }
}
