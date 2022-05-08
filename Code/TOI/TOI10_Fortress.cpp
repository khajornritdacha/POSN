#include<bits/stdc++.h>
using namespace std;
long long m,n,ans;
long long solve(){
    if(n<=m/2){
        long long temp = (m-(2*n))/2;
        ans = n-temp+1;
        if(ans>0)
            return ans;
        else
            return 0;
    }
    return 0;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<20;i++){
        cin >> m >> n;
        cout << solve() << "\n";
    }
    return 0;
}
