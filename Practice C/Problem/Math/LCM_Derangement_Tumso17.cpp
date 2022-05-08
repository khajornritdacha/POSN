#include <bits/stdc++.h>
using namespace std;

const int N = 2e6+10;
using ll = long long;

int n,go[N],cur[N],stored[N];
bool vi[N];
ll lcm = 1, mod = 998244353;

///https://beta.programming.in.th/tasks/tumso17_derangement
///Ans = lcm of every component
///Every node always has exactly one out degree and one in degree

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> go[i];
    }
    for(int i = 1; i <= n; i++){
        if(vi[i]) continue;
        int u = go[i], sz = 1;
        vi[i] = true;
        while(u != i){
            vi[u] = true;
            u = go[u];
            sz++;
        }

        ///Factorization
        vector<int> fac;
        for(int k = 2; k <= sz; k++){
            if(sz%k == 0) fac.emplace_back(k);
            while(sz%k == 0){
                sz /= k;
                cur[k]++;
            }
        }

        ///Calculate LCM
        for(int fa : fac){
            for(int k = 0; k < cur[fa]-stored[fa]; k++)
                lcm = (lcm*fa)%mod;
            stored[fa] = max(stored[fa], cur[fa]);
            cur[fa] = 0;
        }

    }
    cout << lcm << "\n";
    return 0;
}
