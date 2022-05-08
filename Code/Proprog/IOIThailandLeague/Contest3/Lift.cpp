#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m,L[N];
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> L[i];
    }
    for(int i=1; i<=m; i++){
        int x,y,mn=1e9,pos;
        cin >> x >> y;
        for(int j=1; j<=n; j++){
            if(abs(L[j]-x) < mn){
                mn = abs(L[j]-x);
                pos = j;
            }
        }
        cout << pos << "\n";
        L[pos] = y;
    }
}
