#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],k,ans=0,temp=0;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a[x]++;
    }
    cin >> k;
    for(int i=0;i<=k/2;i++){
        int x = k-i;
        if(i!=x){
            ans+=(a[i]*a[k-i]);
            //cout << i << " ";
        }else if(i==x){
            for(int j=1;j<=a[i]-1;j++){
                temp+=j;
            }
        }
    }
    //cout << temp << endl;
    cout << ans+temp;
}
