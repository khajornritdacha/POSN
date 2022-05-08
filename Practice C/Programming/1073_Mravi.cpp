#include<bits/stdc++.h>
using namespace std;
const int N = 7e4+10;
int L,T,n,ans[200010],a[N];
char c[N];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> L >> T >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i] >> c[i];
        if(c[i] == 'L'){
            if(T <= a[i]){
                ans[a[i]-T]++;
                continue;
            }
            int tmp = T-a[i];
            if((tmp/L)%2){
                ans[L-(tmp%L)]++;
            }else{
                ans[tmp%L]++;
            }
        }else{
            if(T <= L-a[i]){
                ans[a[i]+T]++;
                continue;
            }
            int tmp = T-L+a[i];
            if((tmp/L)%2){
                ans[tmp%L]++;
            }else{
                ans[L-(tmp%L)]++;
            }
        }
    }
    for(int i=0; i<=2e5; i++){
        for(int j=0; j<ans[i]; j++){
            cout << i << " ";
        }
    }
}
