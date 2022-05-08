#include<bits/stdc++.h>
#define int long long
using namespace std;
int Q,n,k;
///Draw case to find relation
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Q;
    while(Q--){
        cin >> n >> k;
        if(n <= k+1){
            cout << "B\n";
            continue;
        }
        for(int i=2*k-(k-1); i<=2e9; i=(i*2)-(k-1)){
            if(i >= n){
                if(i==n)
                    cout << "B";
                else
                    cout << "A";
                cout << "\n";
                break;
            }
        }
    }
}
