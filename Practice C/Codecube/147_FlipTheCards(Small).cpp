#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,m,a[N],b[N];

main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i=1; i<=m; i++){
        int x;
        cin >> x;
        for(int i=1; i<=n; i++){
            if(a[i] <= x){
                swap(a[i], b[i]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << a[i] << "\n";
    }
}
