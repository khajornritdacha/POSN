#include<bits/stdc++.h>
using namespace std;

int Q,n,K;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> Q;
    while(Q--){
        cin >> n >> K;
        if(K+1 >= n){
            cout << "B";
        }else{
            int tmp = n-K+1;
            if(__builtin_popcount(tmp) == 1)
                cout << "B";
            else
                cout << "A";
        }
        cout << "\n";
    }

}
