#include<bits/stdc++.h>
using namespace std;
int prime[100],n = 0;
bool chk[100];
main(){
    for(int i=2; i<=20; i++){
        if(chk[i] == false){
            cout << "Prime : " << n << " th = " << i << "\n";
            prime[n] = i;
            n++;
            for(int j=2*i; j<=20; j+=i){
                chk[j] = true;
            }
        }
    }
    ///n = 8;
    cout << "Total prime = " << n << "\n";
    for(int i=0; i<n; i++){
        cout << prime[i] << " ";
    }
}
