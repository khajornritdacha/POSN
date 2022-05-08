#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
using ll = long long;
using pi = pair<int,int>;

///https://atcoder.jp/contests/arc126/tasks/arc126_b

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    vector<pi> vec;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a,b; cin >> a >> b;
        vec.emplace_back(a, b);
    }
    sort(vec.begin(), vec.end(), [&](auto a, auto b){
         if(a.first != b.first) return a.first < b.first;
         return a.second > b.second;
    });

    vector<int> lis;
    for(auto [a, b] : vec){
        //cout << a << " " << b << "\n";
        int k = lower_bound(lis.begin(), lis.end(), b)-lis.begin();
        if(k == lis.size()){
            lis.emplace_back(b);
        }else{
            lis[k] = b;
        }
    }
    cout << lis.size() << "\n";
    return 0;
}
