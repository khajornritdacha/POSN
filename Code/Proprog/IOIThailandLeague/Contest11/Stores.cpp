#include<bits/stdc++.h>
using namespace std;

const int N = 2e1;
int n,a[N],b[N];
double ans = 1e9;

main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    for(int bit = 0; bit < (1<<n); bit++){
        int s1=0,s2=0,n1=0,n2=0;
        for(int i=0; i<n; i++){
            if(bit&(1<<i)){
                s1 += a[i];
                n1++;
            }else{
                s2 += b[i];
                n2++;
            }
        }
        double tmp = (s1*1.0-(1.0*s1*n1/100))+(s2*1.0-(1.0*s2*n2/100));
        ans = min(ans, tmp);
    }
    cout << setprecision(2) << fixed << ans;
}
