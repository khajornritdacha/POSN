#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    cin >> t;
    while(t--){
        long long x,y;
        cin >> x >> y;
        cout << x*(x+1)/2-y*(y+1)/2 << "\n";
    }
}
