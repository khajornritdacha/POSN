#include<bits/stdc++.h>
using namespace std;
int n;
void print(int val){
    for(int i=n-1; i>=0; i--){
        if(val&(1<<i))
            cout << 1;
        else
            cout << 0;
    }
}
main(){
    cin >> n;
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(__builtin_popcount((i|(1<<j))^i)==1){
                print(i);
                cout << " ";
                print(i|(1<<j));
                cout << "\n";
            }
        }
    }

}
