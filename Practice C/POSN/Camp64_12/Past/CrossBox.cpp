#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[15][15];
main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 or i==n-1 or i==j or j==n-i-1 or j==0 or j==n-1)
                cout << '*';
            else
                cout << ' ';
        }
        cout << '\n';
    }
}
