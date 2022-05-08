#include<bits/stdc++.h>
using namespace std;
int ans[100100],cnt,prime[100010],nub;
bitset<1000010> chk;
main(){
    prime[cnt++] = 2;
    for(int i=3; i<=1e5+1000; i+=2){
        if(!chk[i]){
            prime[cnt++] = i;
            for(int j=i; j<=1e5+1000; j+=i){
                chk[j] = true;
            }
        }
    }
    for(int i=0; i<cnt; i++){
        for(int j=i+1; j<cnt; j++){
            if(prime[i] > (1e5+10)/prime[j])
                break;
            ans[prime[i]*prime[j]] = prime[i]*prime[j];
            nub++;
        }
    }
    ///cout << "Compute : " << nub << " times\n";
    ///It does work because it computes only 20K times
    for(int i=1e5; i>=1; i--)
        if(ans[i] == 0)
            ans[i] = ans[i+1];
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
}
