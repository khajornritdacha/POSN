#include<bits/stdc++.h>
using namespace std;
int n,m;
main(){
    while(true){
        cin >> n;
        if(n <= 0)
            break;
        for(int i=1; i<n; i++){
            if(i%5 == 0)
                cout << "X";
            else
                cout << "*";
        }
        cout << n%10 << "\n";
    }
}
