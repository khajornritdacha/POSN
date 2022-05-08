#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int t,sz[10],ava[10],app[10],n;
char str[N],ans[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        for(int i=1; i<=4; i++){
            cin >> sz[i];
            app[i] = 0;
        }
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> str[i];
            app[str[i]-'0']++;
        }

        for(int i=1; i<=4; i++){
            ava[i] = n-app[i];
        }

        for(int i=1; i<=n; i++){
            bool ok = false;
            for(int j=1; j<=4; j++){
                if(str[i] != j+'0' and ava[j] <= sz[j]){
                    sz[j]--;
                    ans[i] = j+'0';
                    ok = true;
                    break;
                }
            }

            if(!ok){
                for(int j=1; j<=4; j++){
                    if(str[i] != j+'0' and sz[j] > 0){
                        sz[j]--;
                        ans[i] = j+'0';
                        break;
                    }
                }
            }

            for(int j=1; j<=4; j++){
                if(str[i] != j+'0')
                    ava[j]--;
            }

        }

        for(int i=1; i<=n; i++){
            cout << ans[i];
        }
        cout << "\n";

    }
}
