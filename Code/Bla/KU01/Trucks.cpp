#include <bits/stdc++.h>
using namespace std;

const int N = 2020;
using ll = long long;
using pi = pair<int,int>;

struct DATA{
    int st, ed;
    bool operator<(const DATA &o) const{
        return ed < o.ed;
    }
};

DATA a[N];
int n, L;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> L;
    for(int i = 1; i <= n; i++){
        cin >> a[i].st >> a[i].ed;
    }

    sort(a+1, a+n+1);

    int ans = 0, pre = -1; //must set pre = -1 cuz st can = 0
    for(int i = 1; i <= n; i++){
        if(a[i].st > pre){
            ans++;
            pre = a[i].ed;
        }
    }

    cout << ans << "\n";

    return 0;
}