#include<bits/stdc++.h>
using namespace std;
long long n,a[1000100],gcd,ans,temp,x,y;
main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ans+=a[i];
        if(n==1){
            if(a[i]!=0)
        cout << 1;
            else
        cout << 0;

        return 0;
        }
        if(i==1){
            if(a[0]==0||a[1]==0){
                gcd = max(a[0],a[1]);
            }else{
            x = max(a[0],a[1]);
            y = min(a[0],a[1]);
            while(x!=0&&y!=0){
                temp = x%y;
                x = y;
                y = temp;
                gcd = max(x,y);
            }
            }
        }else if(i>1){
           x = max(a[i],gcd);
           y = min(a[i],gcd);
           while(x!=0&&y!=0){
                temp = x%y;
                x = y;
                y = temp;
                gcd = max(x,y);
           }
        }
    }
    cout << ans/gcd;
    return 0;
}
