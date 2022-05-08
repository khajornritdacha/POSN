#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;
using pli = pair <long long, int>;

const int N = 1e5+10;

int n, a[N], qs[N];
map<int,int> mp;

//https://www.hackerrank.com/contests/hackerrank-women-technologists-codesprint-2019/challenges/powerful-subarrays

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        qs[i] = qs[i-1] ^ a[i];
    }

    long long ans = 0;
    mp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 30; j++){
            int res = qs[i] ^ (1<<j);
            if(mp.count(res)) ans += mp[res];
        }
        //cout << ans << " ";
        mp[qs[i]]++;
    }

    cout << ans << "\n";
    return 0;
}