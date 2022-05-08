#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using pi = pair<int,int>;
using lb = long double;
int n;
bool vi[N];
int mn[N],x[N],y[N];
priority_queue<pi, vector<pi>, greater<pi>> pq;

main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
        mn[i] = 1e9;
    }
    mn[1] = 0;
    pq.emplace(0, 1);
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        vi[u] = true;
        for(int i=1; i<=n; i++){
            if(vi[i]) continue;
            int tmp = abs(x[u]-x[i])*abs(x[u]-x[i])+abs(y[u]-y[i])*abs(y[u]-y[i]);
            if(tmp < mn[i]){
                mn[i] = tmp;
                pq.emplace(tmp, i);
            }
        }
    }
    int res = *max_element(mn+1, mn+n+1);
    cout << res;
}
