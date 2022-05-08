#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;

bool chk[N];
vector<int> prime;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;

    for(int i = 2; i < N; i++){
        if(chk[i]) continue;
        prime.emplace_back(i);
        for(int j = i; j < N; j += i) chk[j] = true;
    }

    while(t--){
        int x, cnt = 1; cin >> x;
        for(int p : prime){
            if(1ll*p*p > x) break; //very important line
            int res = 0;
            while(x % p == 0){
                res++;
                x /= p;
            }
            cnt *= (res+1);
        }
        if(x != 1) cnt *= 2;
        cout << cnt << "\n";
    }
    return 0;
}