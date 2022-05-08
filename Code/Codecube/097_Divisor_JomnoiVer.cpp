#include<bits/stdc++.h>
using namespace std;


main(){
    long long i,n;
    cin >> n;
    for(i=1; i*i <= n; i++){
        if(n%i == 0)
            cout << i << " ";
    }
    while(i*i >= n)
        i--;
    for(; i>0; i--){
        if(n%i == 0)
            cout << n/i << " ";
    }
}
