//Task : https://codeforces.com/problemset/problem/1619/E

//precalculate the cost for each i
//To calculate cost(i), cost(i-1) must be calculated first unless it is impossible to compute cost(i)
//ans(i) = cost(i) + cnt(i)

#include <bits/stdc++.h>
using namespace std;

void test_case(){
    int n; cin >> n;

    multiset<int> mem;
    vector<long long> ans(n+1, -1), cnt(n+1);
    
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        mem.insert(x);
        cnt[x]++;
    }

    if(mem.count(0)){
        ans[0] = 0;
        mem.erase(mem.find(0));

        for(int i = 1; i < n; i++){
            auto it = mem.upper_bound(i);
            if(it == mem.begin()){
                break;
            }

            it--;
            ans[i] = ans[i-1] + (i-*it);
            mem.erase(it);
        }
    }

    for(int i = 0; i <= n; i++){
        if(i == 0 or ans[i-1] != -1){
            cout << cnt[i] + (i == 0 ? 0 : ans[i-1]) << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << "\n";

    // cout << "ANS : ";
    // for(int i = 0; i <= n; i++) cout << ans[i] << " ";
    // cout << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) test_case();

    return 0;
}