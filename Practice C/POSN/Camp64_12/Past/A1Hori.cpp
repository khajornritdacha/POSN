#include<bits/stdc++.h>
using namespace std;
int n,m;
main(){
    cin >> n;
    for(int i=1; i<=(n+1)/2; i++){
        for(int j=1; j<=(n+1)/2; j++){
            if(i>=j)
                cout << "A";
            else
                cout << "1";
        }
        cout << "\n";
    }
    for(int i=1; i<=(n-1)/2; i++){
        for(int j=1; j<=(n+1)/2; j++){
            if(i+j <= (n+1)/2)
                cout << "A";
            else
                cout << "*";
        }
        cout << "\n";
    }
}
