#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int ans[N],n,m;
bool vi[N],ban[N];

void solve(int lv = 0){
    if(lv == n){
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!vi[i] and (lv != 0 or (lv == 0 and !ban[i]))){
            vi[i] = true;
            ans[lv] = i;
            solve(lv+1);
            vi[i] = false;
        }
    }

    return;
}
int main(void){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        ban[x] = true;
    }

    solve();
    return 0;
}