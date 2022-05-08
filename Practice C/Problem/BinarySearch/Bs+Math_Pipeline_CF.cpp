#include<bits/stdc++.h>
using namespace std;
long long n,k,l,r,mid,ans;
long long sum(int p){
    return (k+k-p+1)*p/2-(p-1);
}
main(){
    cin >> n >> k;
    //cout << (k+2)*(k-1)/2-k+2 << "\n";
    if(n==1){ cout << 0; return 0;}
    if(k>=n){ cout << 1; return 0;}
    else if((k+2)*(k-1)/2-k+2<n){ cout << -1; return 0;}
    l=1,r=k,ans=k;
    while(l<=r){
        mid=(l+r)/2;
        //cout << mid << " " << sum(mid) << "\n";
        if(sum(mid)>=n){
            ans=min(ans,mid);
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout << ans;
}
