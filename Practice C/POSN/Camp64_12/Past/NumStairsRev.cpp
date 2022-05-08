#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,a[N],cnt,x;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1,cnt=n; i<=n; i++,cnt--){
        for(int j=1; j<=i; j++){
            cout << a[cnt];
        }
        cout << "\n";
    }
}
