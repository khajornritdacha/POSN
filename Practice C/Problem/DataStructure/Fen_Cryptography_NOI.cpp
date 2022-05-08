#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+10, mod = 1000000007;

//dp(i) := the number of permutation has the same prefix until i-1 and lexiographically less than input sequence
//ans = 1+sum(dp(i)) ; 1 <= i <= n
//dp(i) = (#a[j] < a[i])*(n-i)!
//https://oj.uz/problem/view/NOI20_crypto

int n, arr[N], fen[N], fac[N];
map<int, int> idx;

void up(int idx, int val){
    if(idx <= 0) return;
    for(; idx < N; idx += idx&-idx) fen[idx] += val;
}

int sum(int idx){
    int res = 0;
    for(; idx; idx -= idx&-idx) res += fen[idx];
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<int> vec;
    fac[0] = 1;
    for(int i = 1; i <= n ; i++){
        cin >> arr[i];
        vec.emplace_back(arr[i]); 
        up(i, 1);
        fac[i] = 1ll*fac[i-1]*i%mod;
    }

    sort(vec.begin(), vec.end()); //compress index
    for(int i = 0; i < n; i++) idx[vec[i]] = i+1;

    int ans = 1;
    for(int i = 1; i <= n; i++){
        ans += 1ll*sum(idx[arr[i]]-1)*fac[n-i]%mod;
        ans %= mod;
        up(idx[arr[i]], -1);
    }
    cout << ans << "\n";


    return 0;
}