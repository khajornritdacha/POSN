#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,a[N],b[N],tot[N];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    reverse(b+1, b+n+1);
    for(int i=1; i<=n; i++){
        tot[i] += (a[i]+b[i])%10;
        tot[i+1] += (a[i]+b[i])/10;
    }
    int mx;
    for(int i=1; tot[i]!=0; i++){
        mx = i;
    }
    for(int i=mx; i>=1; i--){
        cout << tot[i] << " ";
    }
}
