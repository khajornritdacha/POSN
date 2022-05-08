#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e3+100;
int n,m,a[N],b[N],tot[N];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> b[i];
    }
    if(n < m){
        swap(n, m);
        swap(a, b);
    }
    reverse(a+1, a+n+1);
    reverse(b+1, b+m+1);
    int mx = 0;
    for(int i=1; i<=n+10; i++){
        tot[i+1] = (tot[i]+a[i]+b[i])/10;
        tot[i] = (tot[i]+a[i]+b[i])%10;
        if(tot[i] != 0)
            mx = i;
    }

    if(DEBUG){
        for(int i=1; i<=n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
        for(int i=1; i<=m; i++){
            cout << b[i] << " ";
        }
        cout << "\n";
        for(int i=1; i<=mx; i++){
            cout << tot[i] << " ";
        }
        cout << "\n";
    }
    for(int i=mx; i>=1; i--){
        cout << tot[i];
    }
}
