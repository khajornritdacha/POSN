#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
using ll = long long;

ll n;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if((n*(n+1)/2)%2 != 0){ cout << "NO\n"; return 0; }
    int lim = n+1;
    if(n%2) lim--;

    cout << "YES\n" << (n+1)/2 << "\n";
    for(int i = 1; i <= n/2; i+=2){
        cout << i << " " << lim-i << " ";
    }
    cout << "\n";

    cout << n/2 << "\n";
    for(int i = 2; i <= n/2; i+=2){
        cout << i << " " << lim-i << " ";
    }
    if(n%2) cout << n << "\n";
    return 0;
}
