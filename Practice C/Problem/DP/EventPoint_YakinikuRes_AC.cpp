#include <bits/stdc++.h>
using namespace std;

const int N = 5010, M = 210;
using ll = long long;
int n,m;
ll a[N],b[N][M],F[N][N];

///https://atcoder.jp/contests/arc067/tasks/arc067_d

int main(void){
    cin >> n >> m;
    for(int i = 2; i <= n; i++){
        cin >> a[i];
        a[i] += a[i-1];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> b[i][j];
        }
    }

    for(int j = 1; j <= m; j++){
        vector<pair<int,int>> vec(n);
        set<int> ss;
        for(int i = 1; i <=n; i++){
            vec[i-1] = {b[i][j], i};
        }
        sort(vec.rbegin(), vec.rend());

        for(auto &[wa, idx] : vec){
            F[idx][idx] += wa;

            auto it = ss.lower_bound(idx);
            int k, cnt = 0;
            if(it != ss.end()){
                cnt++, k = *it;
                F[idx][k] -= wa;
            }

            if(it != ss.begin()){
                cnt++, it--;
                F[*it][idx] -= wa;
            }

            if(cnt == 2){
                F[*it][k] += wa;
            }
            ss.insert(idx);
        }
    }

    ll ans = -1e18;
    for(int j = 1; j <= n; j++){
        for(int i = j; i >= 1; i--){
            F[i][j] += F[i+1][j]+F[i][j-1]-F[i+1][j-1];
            ans = max(ans, F[i][j]-a[j]+a[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
