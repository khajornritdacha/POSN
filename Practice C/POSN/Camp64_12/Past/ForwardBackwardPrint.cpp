#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int n,a[N],m;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> m;
    if(m >= 0){
        for(int i=1; i<=n; i++){
            cout << a[i]+m << " ";
        }
    }else{
        for(int i=n; i>=1; i--){
            cout << a[i]+m << " ";
        }
    }
}
