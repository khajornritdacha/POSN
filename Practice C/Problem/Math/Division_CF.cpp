#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e3+10;
int p,q;
vector<int> primes;
void TC(){
    vector<pair<int,int>> vec;
    int ans = 1;
    cin >> p >> q;
    if(p%q != 0){
        cout << p << "\n";
        return;
    }
    int tmp = q;
    for(int prime : primes){
        if(prime > tmp)
            break;
        if(tmp%prime == 0){
            int cou = 0;
            while(tmp%prime == 0){
                tmp/=prime;
                cou++;
            }
            vec.emplace_back(prime, cou);
        }
    }
    if(tmp != 1){
        vec.emplace_back(tmp, 1);
    }
    for(auto &[key, val] : vec){
        //cout << "key : " << key << " " << val << "\n";
        int cnt = 0;
        int di = 1;
        tmp = p;
        while(tmp%key == 0 and tmp%q == 0){
            tmp/=key;
            di*=key;
        }
        ans = max(ans, p/di);
    }
    cout << ans << "\n";
}
void gen(){
    bitset<100010> chk;
    primes.emplace_back(2);
    for(int i=3; i<=1e5; i+=2){
        if(!chk[i]){
            primes.emplace_back(i);
            for(int j=i; j<=1e5; j+=i)
                chk[j]=true;
        }
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    gen();
    int t = 1;
    cin >> t;
    while(t--){
        TC();
    }
}
///https://codeforces.com/problemset/problem/1444/A
