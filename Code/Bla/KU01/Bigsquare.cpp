#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<int,int>;

struct DATA{
    int x,y;
    bool operator<(const DATA &o) const{
        return x < o.x;
    }
};

DATA a[N];
int n;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
    }

    sort(a+1, a+n+1);

    map<int,int> mp;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int cur = a[i].x - a[i].y;
        if(mp.count(cur) and mp[cur] < a[i].y){
            ans = max(ans, a[i].y - mp[cur]);
        }
        if(mp.count(cur)) mp[cur] = min(mp[cur], a[i].y);
        else mp[cur] = a[i].y;
    }

    mp.clear();

    for(int i = 1; i <= n; i++){
        int cur = a[i].x + a[i].y;
        if(mp.count(cur) and mp[cur] > a[i].y){
            ans = max(ans, mp[cur] - a[i].y);
        }
        if(mp.count(cur)) mp[cur] = max(mp[cur], a[i].y);
        else mp[cur] = a[i].y;
    }

    cout << ans << "\n";
}