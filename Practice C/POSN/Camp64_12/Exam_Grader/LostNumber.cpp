#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int n,m,a[N],b[N];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    cin >> m;
    for(int i=1; i<=m; i++){
        int x;
        cin >> x;
        b[x]++;
    }
    for(int i=1; i<=10000; i++){
        if(a[i] != b[i]){
            cout << i << " ";
        }
    }
}
