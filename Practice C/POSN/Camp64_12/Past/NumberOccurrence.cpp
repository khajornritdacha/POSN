#include<bits/stdc++.h>
using namespace std;
const int N = 3e6;
int n,a[N],cnt,x;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> x;
    for(int i=1; i<=n; i++){
        if(a[i] == x){
            cout << i << " ";
            cnt++;
        }
    }
    if(!cnt)
        cout << "0";
}
