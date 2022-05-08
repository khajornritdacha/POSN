#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using ll = long long;

int main(void){
    int n;
    vector<int> order;
    int tot = 0, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        order.emplace_back(x);
    }
    sort(order.begin(), order.end());
    for(int now : order){
        tot += now;
        ans += tot*2;
    }
    cout << ans << "\n";
    return 0;
}
