#include <bits/stdc++.h>
using namespace std;

const int N = 20;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

///https://beta.programming.in.th/tasks/tumso15_electrician

int dp[N+1][1<<N],n,a[N][N];

void test_case(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++){
        for(int bit = 0; bit < (1<<n); bit++){
            if(__builtin_popcount(bit) != i) continue;
            for(int j = 0; j < n; j++){
                if(bit&(1<<j)) continue;
                dp[i+1][bit|(1<<j)] = max(dp[i+1][bit|(1<<j)], dp[i][bit]+a[i][j]);
            }
        }
    }

    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < 1<<n; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    cout << dp[n][(1<<n)-1] << "\n";
    return;
}
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
