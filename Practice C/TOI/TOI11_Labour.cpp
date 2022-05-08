#include<bits/stdc++.h>
using namespace std;
long long n,w[1000005],low=0,high=1e18,mid,cap,i,ans=1e18,k;
main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> w[i];
    }
    long long o=1;
    while(low<=high){
    mid = (high+low)/2;
    cap = 0;
        for(i=0;i<n;i++){
            cap+=(mid/w[i]);
        }
        //cout << cap;
        if(cap>=k){
            ans = mid;
            high = mid-1;
        }else if(cap<k){
            low = mid+1;
        }
        /*cout << o << "\n";
        o++;*/
    }
    cout << ans << "\n";
    return 0;
}
