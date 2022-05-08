#include <bits/stdc++.h>
using namespace std;

const int N = 20, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int n;
char ans[N][2];

void solve(int lv = 0, int sz = 0){
    if(lv == n){
        for(int i = 0; i < sz; i++) cout << ans[i][0] << ans[i][1] << "\n";
        cout << "E\n";
        return;
    }

    ans[sz][0] = ans[sz][1] = '-';
    solve(lv+1, sz+1);

    if(lv+2 <= n){
        ans[sz][0] = ans[sz][1] = '|';
        solve(lv+2, sz+1);
    }
    return;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    solve();    
    return 0;
}