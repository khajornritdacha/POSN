#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
int n,a[N],sum;
bitset<N> chk;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for(int i=1,j=n; i<=n; ){
        if(i+2 < j-1){
            chk[i] = chk[i+1] = chk[i+2] = chk[j] = chk[j-1] = true;
            sum += a[i]+a[i+1]+a[i+2]+a[j];
            i+=3;
            j-=2;
        }else{
            break;
        }
    }
    for(int i=1; i<=n; i++){
        if(!chk[i])
            sum += a[i];
    }
    cout << sum;
}
