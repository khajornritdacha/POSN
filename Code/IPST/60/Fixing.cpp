#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10, INF = 1e9;
int n,m,K, a[N];

int main(void){
    cin >> n >> m >> K;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
    }

    vector<int> vec;
    for(int i = 2; i <= m; i++){
        vec.emplace_back(a[i]-a[i-1]-1);
    }
    sort(vec.begin(), vec.end());

    int ans = 0;
    for(int i = 0; i < m-K and i < vec.size(); i++){
        ans += vec[i];
    }
    cout << ans << "\n";
    return 0;
}