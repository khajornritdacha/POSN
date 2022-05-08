#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e3+10;

int n,a[N];

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a+1, a+n+1, greater<int>());

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int j = 1; j <= 200; j++){
        pq.push(j);
        for(int i = 1; i <= 9; i++)
            pq.push(2*j);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += pq.top()*a[i];
        pq.pop();
    }
    cout << ans;
    return 0;
}
