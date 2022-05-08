#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,a[N];
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int l,h,r;
        cin >> l >> h >> r;
        for(int j=l; j<r; j++){
            a[j] = max(a[j], h);
        }
    }
    for(int i=1; i<=600; i++){
        if(a[i] != a[i-1]){
            cout << i << " " << a[i] << " ";
        }
    }
}
