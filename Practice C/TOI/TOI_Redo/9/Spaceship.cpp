#include <bits/stdc++.h>
using namespace std;

const int N = 30, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

int x[N],y[N],z[N],ans = INF, n, m, a[N][3], com[3], sx, sy, sz;
bool vi[N];

void solve(int cx, int cy, int cz, int sum){
    if(min({com[0], com[1], com[2]}) >= n){
        ans = min(ans, sum);
        return;
    }

    for(int i = 1; i <= m; i++){
        if(!vi[i]){
            vi[i] = true;
            for(int k = 0; k < 3; k++) com[k] += a[i][k];
            solve(x[i], y[i], z[i], sum + (cx-x[i])*(cx-x[i]) + (cy-y[i])*(cy-y[i]) + (cz-z[i])*(cz-z[i]));
            vi[i] = false;
            for(int k = 0; k < 3; k++) com[k] -= a[i][k];
        }
    }
}

int main(void){
    cin >> n >> sx >> sy >> sz >> m;
    for(int i = 1; i <= m; i++){
        cin >> x[i] >> y[i] >> z[i];
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }    

    solve(sx, sy, sz, 0);

    cout << ans << "\n";

    return 0;
}