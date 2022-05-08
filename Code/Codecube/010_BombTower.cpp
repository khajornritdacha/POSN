#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 5e5+10;

int n,B;
bitset<N> chk;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> B;
    for(int i=2; i<=n; i++){
        if(!chk[i]){
            B--;
            for(int j=i; j<=n; j+=i)
                chk[j] = true;
        }
    }
    cout << (B >= 0 ? 0 : -B);
}
