#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans=1;
int MOD=1e9+7;
main(){
    cin >> n;
    for(int i=1; i<n; i++){
        ans*=2;
        ans%=MOD;
    }
    cout << (ans*3)%MOD;
}
