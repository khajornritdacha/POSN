#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5+10;

int n,A,B;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(x > 18) B++;
        else A++;
    }

    cout << n+max(0, B-A-1) << "\n";
    return 0;
}
