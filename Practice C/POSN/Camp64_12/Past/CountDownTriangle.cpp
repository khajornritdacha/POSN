#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[510][510];
main(){
    cin >> n;
    for(int i=n,cnt=1; i>=1; i--,cnt%=10){
        for(int j=i; j<=n; j++){
            a[i][j] = cnt;
        }
        cnt++;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i>j)
                cout << " ";
            else
                cout << a[i][j];
        }
        cout << "\n";
    }
}
