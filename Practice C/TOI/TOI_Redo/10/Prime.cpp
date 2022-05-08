#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

bitset<N> chk;
int prime[N/10],sz;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 2; i < N; i++){
        if(chk[i]) continue;
        prime[++sz] = i;
        for(int j = i; j < N; j+=i) chk[j] = true;
    }

    int n; cin >> n;
    cout << prime[n] << "\n";
    return 0;   
}