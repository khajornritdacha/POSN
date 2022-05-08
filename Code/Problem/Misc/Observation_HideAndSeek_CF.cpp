#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

///https://codeforces.com/problemset/problem/1147/A

int n,K,a[N];
bool same[N],ic[N],vi[N],dc[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= K; i++){
        cin >> a[i];
        same[a[i]] = true;
    }
    int ans = 3*n-2;
    for(int i = 1; i <= K; i++){
        ic[a[i]] |= (vi[a[i]-1]);
        dc[a[i]] |= (vi[a[i]+1]);
        vi[a[i]] = true;
    }
    for(int i = 1; i <= n; i++){
        ans -= ic[i]+dc[i]+same[i];
    }
    cout << ans << "\n";
    return 0;
}
