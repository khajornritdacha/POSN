#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,K,D[N],old;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> D[i];
        //cout << "OLD : " <<  old << "\n";
        int now = D[i]-old;
        old -= D[i];
        if(old < 0)
            old = 0;
        if(now <= 0){
            cout << "0";
        }else{
            int tmp = (now+K-1)/K;
            old += tmp*K-now;
            cout << tmp;
        }
        cout << "\n";
    }

}
