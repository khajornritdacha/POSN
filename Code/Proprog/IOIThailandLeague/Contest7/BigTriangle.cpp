#include<bits/stdc++.h>
using namespace std;
int n;
double x[110],y[110],ans;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            for(int k=j+1; k<=n; k++){
                ans = max(ans, abs(((x[k]*y[i])+(x[i]*y[j])-(x[k]*y[j])-(x[i]*y[k])-(x[j]*y[i])+(x[j]*y[k]))/2));
            }
        }
    }
    cout << setprecision(3) << fixed << ans;
}
