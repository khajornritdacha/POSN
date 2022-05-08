#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 2e5+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;
using ll = long long;

ll ans;
int n,K,a[N];
unordered_map<int,int> cnt(N);

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    ll ans = 0;
    for(int l = 1, r = 1, ty = 0; r <= n; r++){ 
        if(++cnt[a[r]] == 1) ty++; //find the minimum l such that the number of distinct values between [l, r] <= K
        while(l <= n and ty > K){
            if(--cnt[a[l]] == 0) ty--;
            l++;
        }
        ans += r-l+1;
    }
    cout << ans << "\n";
    return 0;
}