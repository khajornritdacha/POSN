#include<bits/stdc++.h>
#include "dual.h"
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using ll = long long;

ll solve(int n, int V, vector<int> A){
    ll dp[n+1] = {};
    deque<pair<ll,ll>> dq;
    A.emplace_back(0);
    dq.emplace_back(A[0], 0);
    for(int i=1; i<=n; i++){
        while(!dq.empty() and i-dq.front().second > V)
            dq.pop_front();
        dp[i] = dp[i-1]+dq.front().first;
        while(!dq.empty() and A[i] <= dq.back().first)
            dq.pop_back();
        dq.emplace_back(A[i], i);
    }
    return dp[n];
}

long long dual_fuel(int n, int V, vector<int> &A, vector<int> &B){
    ll ans = 0;
    ans += solve(n, V, A);
    ans += solve(n, V, B);
    return ans;
}
/*
main(){
    int n,V;
    vector<int> A,B;
    cin >> n >> V;
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        A.emplace_back(x);
    }
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        B.emplace_back(x);
    }
    cout << dual_fuel(n, V, A, B) << "\n";
}
/*
4 2
3 1 1 4
1 5 1 6
*/
