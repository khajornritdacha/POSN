#include<bits/stdc++.h>
using namespace std;
int sum,mn=1e9;
main(){
    for(int i=1; i<=4; i++){
        int x;
        cin >> x;
        sum+=x;
        mn = min(mn, x);
    }
    cout << sum-mn << "\n";
}
