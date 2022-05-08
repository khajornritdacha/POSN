#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int di[N],p[N],Z,K,n,mx[2],sz;
bitset<N> chk;
vector<int> prime;

int solve(int val, int lv = 1, int si = -1, int lc = 1){ //calculate the number of number that is divisible by prime factor of K (the numbre of elements that its gcd with K isn't 1)
    if(lv == sz+1) return (lc == 1) ? 0 : val/lc*si;
    return solve(val, lv+1, si*-1, lc*di[lv]) + solve(val, lv+1, si, lc);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Z >> K >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }

    for(ll i = 2; i*i <=K; i++){
        if(K%i == 0){
            di[++sz] = i;
            while(K%i == 0) K /= i;
        }
    }
    if(K != 1) di[++sz] = K;    

    // cout << "Divisor of K : ";
    // for(int i = 1; i <= sz; i++) cout << di[i] << " \n"[i==sz];

    int ans = 0;
    mx[0] = mx[1] = -INF;
    for(int i = 1; i <= n; i++){
        int sp = solve(p[i]);
        int sn = p[i] - sp;

        //cout << p[i] << " " << sp << " " << sn << "\n";

        ans = max({ans, sp-sn+mx[0], sn-sp+mx[1]});

        int ssp = solve(p[i]-1);
        int ssn = p[i] -1 -ssp;
        mx[0] = max(mx[0], -ssp+ssn);
        mx[1] = max(mx[1], -ssn+ssp);    
    }

    cout << ans << "\n";

    return 0;
}