#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int n;

void pri(int bit){
    for(int i = n-1; i >= 0; i--){
        cout << (bit&(1<<i) ? 1 : 0);
    }
    return;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int bit = 0; bit < (1<<n); bit++){
        for(int j = 0; j < n; j++){
            if((bit & (1<<j)) == 0){
                pri(bit);
                cout << " ";
                pri(bit|(1<<j));
                cout << "\n";
            }
        }
    }
    return 0;
}