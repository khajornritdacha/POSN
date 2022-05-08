#include<bits/stdc++.h>
using namespace std;
int mx,la=0,cnt=1,num;
main(){
    while(true){
        int x;
        cin >> x;
        if(x == 0)
            break;
        if(x == la){
            cnt++;
        }else{
            cnt = 1;
        }
        if(cnt > mx){
            mx = cnt;
            num = x;
        }
        la = x;
    }
    cout << mx << "\n" << num << "\n";
}
