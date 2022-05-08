#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
main(){
    cin >> n;
    a[0]=a[n+1]=1e9;
    int l=1, r=n, mid;
    while(l<=r){
        mid = (l+r)/2;
        for(int i=mid-1; i<=mid+1; i++){
            if(a[i] == 0){
                cout << "? "<<i<<endl;
                cin >> a[i];
            }
        }


        if(mid>=1 and mid<=n and a[mid]<a[mid-1] && a[mid]<a[mid+1]){
                cout << "! "<<mid<<endl;
                return 0;
        }

        if(a[mid-1] < a[mid]){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
}
