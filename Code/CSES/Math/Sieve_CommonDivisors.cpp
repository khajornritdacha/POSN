#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

int cnt[N],n;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        cnt[x]++;
    }

    int ans = 1;
    for(int i = 2; i < N; i++){
        int res = 0;
        for(int j = i; j < N; j += i){
            res += cnt[j];
            if(res >= 2) break;
        }

        if(res >= 2)
            ans = i;
    }

    cout << ans << "\n";
    return 0;
}