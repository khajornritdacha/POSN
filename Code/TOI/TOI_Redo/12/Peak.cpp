#include <bits/stdc++.h>
using namespace std;

const int N = 5e6+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;

int a[N],dom[N],n,K,k,ans[N],L;

int main(void){
    scanf(" %d %d", &n, &K);
    for(int i = 1; i <= n; i++){
        scanf(" %d", &a[i]);
    }
    if(a[1] > a[2]) dom[++k] = a[1];
    if(a[n] > a[n-1]) dom[++k] = a[n];
    for(int i = 2; i < n; i++){
        if(a[i] > a[i-1] and a[i] > a[i+1]) dom[++k] = a[i];
    }

    sort(dom+1, dom+k+1, greater<int>());

    int pre = -1;
    for(int i = 1; i <= k; i++){
        if(dom[i] == pre) continue;
        ans[++L] = dom[i];
        pre = dom[i];
        if(L == K) break;
    }

    if(L < K) reverse(ans+1, ans+L+1);
    for(int i = 1; i <= L; i++) printf("%d\n", ans[i]);
    if(L == 0) printf("-1\n");

    return 0;
}