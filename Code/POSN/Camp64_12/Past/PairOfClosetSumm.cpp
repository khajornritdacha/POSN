#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,K,a[N],x,y,mn=2e9;
main(){
    cin >> K >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int sum = a[i]+a[j];
            if(abs(K-sum) < mn){
                mn = abs(K-sum);
                x = a[i];
                y = a[j];
            }else if(abs(K-sum) == mn){
                if(abs(a[i]-a[j]) < abs(x-y)){
                    x = a[i];
                    y = a[j];
                }
            }
        }
    }
    cout << x+y << "\n" << min(y,x) << " " << max(x,y);
}
