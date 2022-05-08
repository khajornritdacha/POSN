#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N],n,ans1,ans2;
main(){
    while(true){
        cin >> a[n];
        if(a[n] == 0)
            break;
        n++;
    }
    for(int i=1; i<n-1; i++){
        if(a[i] > a[i-1] and a[i] > a[i+1]){
            ans1++;
        }
        if(a[i] < a[i-1] and a[i] < a[i+1]){
            ans2++;
            //cout << i << " " << a[i] << "\n";
        }
    }
    cout << ans1 << "\n" << ans2;
}
