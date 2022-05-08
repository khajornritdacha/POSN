#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n,K,a[N],le[N],ans[N];
void up(int &idx){
    idx++;
    if(idx == n+1)
        idx = 1;
}
main(){
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        le[i] = 1;
    }
    int now = 0, idx = 1;
    for(int i=1; i<=n; i++, now++){
        now%=K;
        int x;
        cin >> x;
        if(i == n){
            for(int j=1; j<=n; j++){
                if(le[j]){
                    ans[now]+=a[j];
                    break;
                }
            }
            for(int j=0; j<K; j++){
                cout << ans[j] << "\n";
            }
            return 0;
        }
        //cout << "I: " << i << "\nJ\n";
        for(int j=0; j<x; j++){
            up(idx);
            while(le[idx] == 0){
                up(idx);
            }
            //cout << idx << " " << le[idx] << "\n";
        }
        //cout << "I : " << i << " = " << idx << "\n";
        ans[now] += a[idx];
        le[idx] = 0;
        while(le[idx] == 0){
            up(idx);
        }
        //cout << "I : " << i << " = " << idx << "\n";
    }
}
