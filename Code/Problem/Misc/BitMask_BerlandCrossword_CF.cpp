#include<bits/stdc++.h>
using namespace std;
int t,n,RR,DD,UU,LL;
main(){
    cin >> t;
    while(t--){
        bool ok = false;
        cin >> n >> UU >> RR >> DD >> LL;
        for(int i=0; i<16; i++){
            int U=UU, R=RR, D=DD, L=LL;
            if(i&1){
                U--;
                L--;
            }
            if(i&2){
                U--;
                R--;
            }
            if(i&4){
                D--;
                L--;
            }
            if(i&8){
                D--;
                R--;
            }
            if(min({U,L,R,D}) >= 0 && max({U,R,L,D}) <= n-2){
                ok = true;
                break;
            }
        }
        if(ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
///https://codeforces.com/contest/1494/problem/B
