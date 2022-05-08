#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+100;
int n,m,a[N];

main(){
    cin >> n >> m;
    for(int i=1; i<=n-m; i++){
        int x;
        cin >> x;
        a[x] = true;
    }
    for(int i=1; i<=n; i++){
        if(a[i] == 0)
            cout << i << "\n";
    }
}
