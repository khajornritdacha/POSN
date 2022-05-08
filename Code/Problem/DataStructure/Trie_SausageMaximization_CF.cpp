#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

//Trie
//Greedily choose path that will yield a maximum value (from 2^k to 2^0)
//https://codeforces.com/problemset/problem/282/E

int n;
vector<vector<int>> node;
long long arr[N];

void add(long long val){   
    int idx = 0;
    // cout << "ADD " << val << " : ";
    for(int i = 60; i >= 0; i--){
        int cur = ((val&(1ll<<i)) != 0);
        // cout << cur;
        if(node[idx][cur] == 0){
            node[idx][cur] = node.size();
            node.emplace_back(vector<int>(2));
        }
        idx = node[idx][cur];
    }
    // cout << "\n";
}

long long fi(long long val){
    int idx = 0;
    long long res = 0;
    // cout << "FI " << val << " : ";
    for(int i = 60; i >= 0; i--){
        int cur = ((val&(1ll<<i)) != 0);
        // cout << cur;
        if(node[idx][!cur] != 0){
            idx = node[idx][!cur];
            res |= (1ll<<i);
        } else if(node[idx][cur] != 0){
            idx = node[idx][cur];
        } else {
            assert(0); //there should always exist a path from root to some leaf
        }
    }
    // cout << " = " << res << "\n";
    return res;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    long long pre = 0;
    for(int i = 1; i <= n; i++) cin >> arr[i], pre ^= arr[i];

    long long ans = pre, suf = 0;

    node.emplace_back(vector<int>(2));
    add(0);
    for(int i = n; i >= 1; i--){
        pre ^= arr[i];
        suf ^= arr[i];
        add(suf);
        ans = max(ans, fi(pre));
    }

    cout << ans << "\n";

    return 0;
}