///https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1266
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll m[20],N,M,ans;
ll lcm(ll a, ll b){
    return a/__gcd(a,b)*b;
}
void gen(int lv=0, int sign=-1, ll now=1){
    if(lv == M){
        if(now == 1)
            return;
        ans+=(N/now*sign);
        return;
    }
    gen(lv+1, sign*-1, lcm(now, m[lv]));
    gen(lv+1, sign, now);
}
main(){
    ///Find number of number that cannot divisible by set of M
    ///N-[ n(a)+n(b)-n(a U b)...]
    while(cin >> N >> M){
        ans = 0;
        for(int i=0; i<M; i++){
            cin >> m[i];
        }
        gen();
        cout << N-ans << "\n";
    }
}
/*
10 2
2 3
*/
