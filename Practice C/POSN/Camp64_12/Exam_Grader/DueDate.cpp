#include<bits/stdc++.h>
using namespace std;
int n,K,cnt=1;
main(){
    cin >> K >> n;
    int tmp = K*100;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        while(true){
            if(tmp-x >= 0){
                tmp-=x;
                cout << cnt << "\n";
                if(tmp == 0){
                    tmp = K*100;
                    cnt++;
                }
                break;
            }
            x-=tmp;
            tmp = K*100;
            cnt++;
        }
    }
}
