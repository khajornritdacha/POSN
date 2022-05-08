#include<bits/stdc++.h>
using namespace std;
int n;
bool ok = true;
main(){
    cin >> n;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            ok = false;
            break;
        }
    }
    cout << n;
    if(ok and n!=1)
        cout << " is prime";
    else
        cout << " is not prime";
}
