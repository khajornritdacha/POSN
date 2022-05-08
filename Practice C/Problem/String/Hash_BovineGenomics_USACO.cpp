#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 510;

int n,m;
string str[2][N];
ll hh[2][N], base = 31;

///http://www.usaco.org/index.php?page=viewproblem2&cpid=741

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    cin >> n >> m;
    for(int k : {0, 1}){
        for(int i = 1; i <= n; i++){
            cin >> str[k][i];
        }
    }

    //for(int k : {0, 1}){ cout << "K : " << k << "\n"; for(int i = 1; i <= n; i++) cout << str[k][i] << "\n";}

    int l = 1, r = m, ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        bool ok = false;
        //cout << "MID : " << mid << "\n";

        for(int i = 1; i <= n; i++) hh[0][i] = hh[1][i] = 0;
        ll pw = 1;

        for(int j = 0; j < mid-1; j++){ ///initialize
            pw *= base;
            for(int k : {0, 1}){
                for(int i = 1; i <= n; i++){
                    hh[k][i] = (hh[k][i]*base + str[k][i][j]-'A'+1);
                }
            }
        }

        for(int j = mid-1; j < m; j++){ ///processing
            set<ll> ss;
            int cnt = 0;

            for(int i = 1; i <= n; i++){
                hh[1][i] = (hh[1][i]*base + str[1][i][j]-'A'+1);
                ss.insert(hh[1][i]);
            }

            for(int i = 1; i <= n; i++){
                hh[0][i] = (hh[0][i]*base + str[0][i][j]-'A'+1);
                cnt += (ss.count(hh[0][i]));
            }

            for(int k : {0, 1}){
                for(int i = 1; i <= n; i++){
                    hh[k][i] -= pw*(str[k][i][j-mid+1]-'A'+1);
                }
            }
            //cout << "J : " << j << " " << cnt << "\n";
            if(cnt == 0){
                ok = true;
                break;
            }
        }

        if(ok){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout << ans << "\n";
    return 0;
}
