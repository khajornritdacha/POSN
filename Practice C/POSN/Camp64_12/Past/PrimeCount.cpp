#include<bits/stdc++.h>
using namespace std;
int n,cnt;
bitset<6000100> chk;
main(){
    cin >> n;
    if(n>=2)
        cnt++;
    for(int i=3; i<=n; i+=2){
        if(!chk[i]){
            cnt++;
            for(int j=i; j<=n; j+=i){
                chk[j] = true;
            }
        }
    }
    cout << cnt;
}
