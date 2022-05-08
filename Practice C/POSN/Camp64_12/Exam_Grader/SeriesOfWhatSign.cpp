#include<bits/stdc++.h>
using namespace std;
int a[100],sum,n;
main(){
    for(int i=1; i<=4; i++)
        cin >> a[i];
    cin >> n;
    for(int i=5; i<=n; i++){
        a[i] = (a[i-2]+a[i-4])*5/4;
        if(a[i]%2)
            a[i]*=-1;
    }
    for(int i=1; i<=n; i++)
        sum += a[i];
    cout << sum;
}
