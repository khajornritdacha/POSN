#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;
const int maxn=1e5+10;
using ll = long long;
ll fen[maxn][15],ans;
int a[maxn];
int N,K;
void up(int i, int lv, ll val){
    while(i<=N){
        fen[i][lv]+=val;
        i+=i&-i;
    }
}
ll sum(int i, int lv){
    ll tmp = 0;
    while(i>=1){
        tmp+=fen[i][lv];
        i-=i&-i;
    }
    return tmp;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> a[i];
    }
    ///dp[i][k] += dp(j,k-1); j<i && a[i]>a[j]
    ///opt by using fenwick tree to find sum instead
    for(int i=1; i<=N; i++){
        up(a[i], 0 , 1);
        for(int k=1; k<=K; k++){
            up(a[i], k, sum(a[i]-1, k-1));
        }
    }
    if(DEBUG){
        for(int k=0; k<=K; k++){
            for(int i=1; i<=N; i++){
                cout << sum(i, k)-sum(i-1,k) << " ";
            }
            cout << "\n";
        }
    }

    for(int i=1; i<=N; i++){
        ans+=sum(N, K);
    }
    cout << sum(N,K) << "\n";
}
///https://codeforces.com/contest/597/problem/C
