#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,x[N],y[N],ans,tmp[3];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j+1; k<=n; k++){
                if(x[i] == x[j] and x[j] == x[k]) continue;
                if(y[i] == y[j] and y[j] == y[k]) continue;
                if((y[j]-y[i])*(x[k]-x[i]) == (y[k]-y[i])*(x[j]-x[i]) and (y[j]-y[i])*(x[k]-x[j]) == (y[k]-y[j])*(x[j]-x[i])) continue;
                ans++;
            }
        }
    }
    cout << ans;
}
