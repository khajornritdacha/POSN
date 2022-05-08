#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 1e6+10;

using lb = double;
int n;
lb a[N],b[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
        b[i] /= 10000;
    }

    lb ans = 0.0, now = 0.0, mul = 1.0;
    for(int i=1,j=1; i<=n; i++){
        now += a[i]/b[i];
        mul *= b[i];
        while(i-j > 0 and (now-(a[j]/b[j]))/b[j] > now){
            now -= (a[j]/b[j]);
            mul /= b[j];
            j++;
        }
        ans = max(ans, now*mul);
    }
    cout << (long long)(floor(ans*10000+0.5)) << "\n";
}
