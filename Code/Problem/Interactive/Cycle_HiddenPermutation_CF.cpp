//task : https://codeforces.com/problemset/problem/1621/C
//1st observation : if ask(i) == i then every elements that is of the same cycle as i holds ask(j) == j as well (before asking a new query)
//then we can start backtracking from there

#include <bits/stdc++.h>
using namespace std;

inline int ask(int x){
    cout << "? " << x << endl;
    int res; cin >> res;

    assert(res != 0);

    return res;
}

void test_case(){
    int n; cin >> n;
    int ans[n+5] = {};
    for(int i = 1; i <= n; i++){
        if(ans[i]) continue;

        vector<int> vec;
        int st = ask(i), res = 0;
        vec.emplace_back(st);

        do{
            res = ask(i);
            vec.emplace_back(res);
        } while(res != st);

        for(int k = 0; k+1 < (int)vec.size(); k++) ans[vec[k]] = vec[k+1];
    }

    cout << "! ";
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return;
}

int main(void){
    int t; cin >> t;
    while(t--) test_case();

    return 0;
}