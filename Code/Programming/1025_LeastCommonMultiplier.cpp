#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,lc;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(i==1){
            lc = x;
            continue;
        }
        lc = lc/__gcd(x, lc)*x;
    }
    cout << lc << "\n";
}
