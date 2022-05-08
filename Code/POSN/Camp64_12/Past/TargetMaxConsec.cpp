#include<bits/stdc++.h>
using namespace std;
int cnt,want,con,mx;
main(){
    cin >> want;
    while(true){
        int x;
        cin >> x;
        if(x == 0)
            break;
        if(want == x){
            cnt++;
            con++;
            mx = max(mx, con);
        }else{
            con = 0;
        }
    }
    cout << mx << "\n" << cnt;
}
