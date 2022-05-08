#include<bits/stdc++.h>
using namespace std;
int n,K,cnt;
bool chk[1010];
main(){
    cin >> n >> K;
    for(int i=2; i<=n; i++){
        if(!chk[i]){
            for(int j=i; j<=n; j+=i){
                if(!chk[j] and ++cnt == K){
                    cout << j;
                    return 0;
                }
                chk[j]=true;
            }
        }
    }
}
