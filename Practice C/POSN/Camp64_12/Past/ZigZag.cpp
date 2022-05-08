#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,a[100010],oe,eo,ans;
main(){
    while(true){
        cin >> a[n];
        if(a[n] <= 0)
            break;
        n++;
    }
    for(int i=0; i<n-1; i++){
        if(a[i]%2 == 1 and a[i+1]%2 == 0){
            oe++;
            i++;
        }else{
            oe = 0;
        }
        ans = max(ans, oe);
        //cout << a[i] << " ";
    }
    for(int i=0; i<n-1; i++){
        if(a[i]%2 == 0 and a[i+1]%2 == 1){
            eo++;
            i++;
        }else{
            eo = 0;
        }
        ans = max(ans, eo);
    }
    cout << ans;
}
