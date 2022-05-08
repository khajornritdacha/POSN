#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

int cp[N], Q;
bool chk[N];
vector<int> prime;

//https://www.hackerrank.com/contests/crack-n-code-october-2021/challenges/prime-forest/problem
//(m^3-n+1)(n^3-m+1) = p*j
//a * b = p*j
//then a = p*l and a = m^3-n+1
//m^3 - (n-1) = p*l
//m^3 mod p = n-1 mod p
//m^3 mod p +1 = n

int fi(int x){ return cp[x] = (cp[x] == x ? x : fi(cp[x])); }

inline bool uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u == v) return false;
    cp[u] = v;
    return true;
}

int main(void){
    for(int i = 2; i < N; i++){
        if(chk[i]) continue;
        prime.emplace_back(i);
        if(prime.size() >= 75000) break;
        for(int j = i+i; j < N; j+=i){
            chk[j] = true;
        }
    }

    cin >> Q;
    while(Q--){
        int K; cin >> K;
        int n = prime[K-1];
        
        for(int i = 1; i <= n; i++) cp[i] = i;

        int ans = n;
        for(int i = 1; i <= n; i++){
            int tmp = (1ll*i*i*i)%n;
            // cout << i << " " << tmp+1 << "\n";
            if(i != tmp+1 and tmp+1 <= n and uni(i, tmp+1)) ans--;
        }
        cout << ans << "\n";
    }
    return 0;   
}