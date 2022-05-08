#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
const int N = 1e2+10;
int x[N],y[N],n;
double ans = 0;
main(){
    cout << setprecision(3) << fixed;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> x[i] >> y[i];
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j+1; k<=n; k++){
                ans = max(ans, 1.0*abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-y[i]*x[j]-y[j]*x[k]-y[k]*x[i])/2);
            }
        }
    }
    cout << ans;
}
