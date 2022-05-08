#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;

int n,A[N],L[N],B[N],R[N];
long long ans;

void dfs(int u){
    if(A[u] == 0){
        dfs(L[u]);
        L[u] = 2*max(L[L[u]], R[L[u]]);
    }
    if(B[u] == 0){
        dfs(R[u]);
        R[u] = 2*max(L[R[u]], R[R[u]]);
    }
    ans += max(L[u], R[u])-min(L[u], R[u]);
}

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> A[i] >> L[i] >> B[i] >> R[i];
    }

    dfs(1);

    cout << ans << "\n";
    return 0;
}
