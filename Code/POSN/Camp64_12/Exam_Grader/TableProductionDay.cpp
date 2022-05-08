#include<bits/stdc++.h>
using namespace std;
int a,b,m,n,mx;
main(){
    cin >> a >> b >> m >> n;
    if(m!=0 and a==0 or n!=0 and b==0){
        cout << "Unable to finish order\n";
        return 0;
    }
    a*=6; b*=10;
    if(a!=0)
        mx = max((m+a-1)/a,mx);
    if(b!=0)
        mx = max((n+b-1)/b,mx);
    cout << mx;
}
