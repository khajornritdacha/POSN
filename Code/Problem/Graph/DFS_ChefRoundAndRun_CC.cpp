#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 1e5+10;
using lb = long double;
using ll = long long;
using pi = pair<int,int>;

int cnt,vi[N],go[N],st,n,a[N];
///https://www.codechef.com/AUG16/problems/CHEFRRUN
void dfs(int u){
    if(vi[u] == 2) return;
    if(vi[u] == 1){
        st = u;
        return;
    }
    vi[u] = 1;
    dfs(go[u]);
    if(st != -1){
        cnt++;
        if(st == u)
            st = -1;
    }
    vi[u] = 2;
}

void test_case(){
    cnt = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        go[i] = (a[i]+i)%n+1;
        //cout << go[i] << " \n"[i==n];
        vi[i] = 0;
    }
    for(int i=1; i<=n; i++){
        if(!vi[i]){
            st = -1;
            dfs(i);
        }
    }
    cout << cnt << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
}
