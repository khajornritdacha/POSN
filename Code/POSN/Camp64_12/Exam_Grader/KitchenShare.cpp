#include<bits/stdc++.h>
using namespace std;

int n,a[1010],cnt;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(a[i]-a[i-1] >= x){
            cnt++;
        }
    }
    cout << cnt;
}
