#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+10;

///https://www.spoj.com/problems/ADACOINS/

void test_case(){
    int n,Q;
    bitset<N> bit;
    vector<int> ans(N);
    cin >> n >> Q;
    bit[0] = 1;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        bit |= (bit << x);
    }
    ans[0] = 1;
    for(int i = 1; i <= 1e5; i++){
        ans[i] = bit[i]+ans[i-1];
    }
    while(Q--){
        int a,b;
        cin >> a >> b;
        cout << ans[b]-ans[a-1] << "\n";
    }
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
