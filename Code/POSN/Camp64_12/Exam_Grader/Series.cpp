#include<bits/stdc++.h>
using namespace std;
int b,sum;
main(){
    cin >> b;
    for(int i=1,j=1; j<=b; j+=i,i++){
        sum += i*j;
    }
    cout << sum;
}
