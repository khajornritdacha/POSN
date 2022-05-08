#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using lb = long double;

int n,K,a[N];
bool res[N];


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        res[a[i]] = 1;
    }
    for(int i = a[1]; i <= K; i++){
        for(int j = 1; j <= n; j++){
            if(a[j] >= i) break;
            res[i] |= !res[i-a[j]];
        }
    }
    if(res[K]) cout << "First";
    else cout << "Second";
    return 0;
}
