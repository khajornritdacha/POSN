#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

const int N = 2e6+10;

int n, ex, dis[N], cnt[2], node;
vector<int> vec;
char str[N];
vector<pi> G[N];

//https://www.hackerrank.com/contests/hourrank-30/challenges/jerrys-expression/problem

void precal(int cur){
    int v = vec.back(); vec.pop_back();
    int op = vec.back(); vec.pop_back();

    ex++;
    //cout << cur << " " << v << " " << ex << " " << op << "\n";
    G[ex].emplace_back(v, 0); //positive
    if(op == -1){
        G[ex].emplace_back(cur, 0);
    } else {
        G[ex].emplace_back(cur, 1); //neg
    }
    vec.push_back(ex);
    return;
}

void dfs(int u, int cur = 0){
    dis[u] = cur;
    if(u <= node)
        cnt[cur]++;
    for(auto [v, w] : G[u]){
        dfs(v, cur ^ w);
    }
}

void test_case(){
    cin >> (str+1);
    n = strlen(str+1);

    for(int i = 1; i <= n; i++) ex += (str[i] == '?');

    for(int i = 1; i <= n; i++){
        if(str[i] == '?'){
            node++;
            vec.push_back(node);
            while(vec.size() >= 3 and vec[(int)vec.size()-2] > 0){
                int tmp = vec.back();
                vec.pop_back();
                precal(tmp);
            }
        } else if(str[i] == '+'){
            vec.push_back(-1);
        } else {
            vec.push_back(-2);
        }
    }

    while(vec.size() > 2){
        int u = vec.back(); vec.pop_back();
        precal(u);
    }   

    assert(vec.size() == 1);

    // for(int i = ex; i >= 1; i--){
    //     cout << "CUR: " << i << "\n";
    //     for(auto [v, w] : G[i]) cout << v << " " << w << "\n";
    // }

    dfs(ex);

    int mx = max(cnt[0], cnt[1]), mn = min(cnt[0], cnt[1]);
    int R = mx%mn, res = mx/mn;

    //cout << cnt[0] << " " << cnt[1] << "\n";

    for(int i = 1; i <= node; i++){
        if(cnt[dis[i]] == mn){
            cout << res+(R > 0) << "\n";
            R--;
        } else {
            cout << "1\n";
        }
    }

    return;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    while(t--){
        test_case();
    }    
    return 0;
}