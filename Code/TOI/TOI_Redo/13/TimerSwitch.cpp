#include <bits/stdc++.h>
using namespace std;

const int N = 5e6+10, INF = 1e9;
using pi = pair<int,int>;
using ll = long long;

int n,base=31;
bitset<N> str;
ll want;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        char c; cin >> c;
        str[i] = c - '0';
        want = (want*base) + str[i];
    }

    ll pw = 1;
    for(int i = 0; i < n-1; i++) pw *= base;

    ll now = want;
    for(int i = 1; i <= n; i++){ //check if it can be turned into the first one after it was cut its prefix from 1...i
        now -= pw*str[i];
        now = (now*base)+str[i];
        if(now == want){
            cout << i << "\n";
            break;
        }
    }
}