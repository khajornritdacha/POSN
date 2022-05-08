#include<bits/stdc++.h>
using namespace std;
int n,m;
main(){
    cin >> n;
    for(int i=1; i<=(n+1)/2; i++){
        for(int j=1; j<=(n+1)/2; j++){
            if(j>=i)
                cout << 'A';
            else
                cout << '1';
        }
        for(int j=1; j<=(n-1)/2; j++){
            if(j+i <= (n-1)/2+1)
                cout << 'A';
            else
                cout << '*';
        }
        cout << '\n';
    }
}
