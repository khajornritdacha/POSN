#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n,d[N];
///Find number of divisor

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            d[j]++;
        }
    }
    for(int i=1; i<=n; i++){
        cout << "Number of Divisor of " << i << ": " << d[i] << "\n";
    }
}
