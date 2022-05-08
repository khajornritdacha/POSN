#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
using ll = long long;
using pi = pair<int,int>;

int n,X[N],Y[N];
vector<int> nx, ny;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> X[i] >> Y[i];
        ny.emplace_back(X[i] + Y[i]); //rotate graph
        nx.emplace_back(X[i] - Y[i]); 
    }

    //north is Y and right is X (view as vector) then north right is X + Y and South East is X - Y
    //then find median from rotated graph

    sort(ny.begin(), ny.end());
    sort(nx.begin(), nx.end());

    int mx = nx[n/2], my = ny[n/2];

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(mx - nx[i]) + abs(my - ny[i]);
    }
    cout << ans << "\n";


    return 0;
}