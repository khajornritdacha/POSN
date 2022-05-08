#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int dp[N],sum[N],val[N],sumall;
vector<int> vec[N];
///https://oj.uz/problem/view/IOI10_traffic
void fisum(int u, int p){
    sum[u] = val[u];
    sumall += val[u];
    for(int v : vec[u]){
        if(v == p) continue;
        fisum(v, u);
        sum[u] += sum[v];
    }
}

void solve(int u, int p){
    int res = 0;
    for(int v : vec[u]){
        if(v == p) continue;
        solve(v, u);
        res = max(res, sum[v]);
    }
    dp[u] = max(res, sumall-sum[u]);
}

int LocateCentre(int n, int P[], int E1[], int E2[]){
    for(int i=0; i<n; i++){
        val[i] = P[i];
        dp[i] = 2e9;
    }
    for(int i=0; i<n-1; i++){
        vec[E1[i]].emplace_back(E2[i]);
        vec[E2[i]].emplace_back(E1[i]);
    }
    fisum(0, 0);
    solve(0, 0);
    int mn = *min_element(dp, dp+n);
    for(int i=0; i<n; i++){
        if(dp[i] == mn)
            return i;
    }
}

/*main(){
    int n,P[N],S[N],D[N];
    cin >> n;
    //cout << "TEST";
    for(int i=0; i<n; i++){
        cin >> P[i];
    }
    for(int i=0; i<n-1; i++){
        cin >> S[i] >> D[i];
    }
    cout << LocateCentre(n, P, S, D) << "\n";
    for(int i=0; i<n; i++){
        printf("Sum %d : %d\n", i, sum[i]);
    }
}*/
