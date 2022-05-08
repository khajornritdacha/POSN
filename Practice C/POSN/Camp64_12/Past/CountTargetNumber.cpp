#include<bits/stdc++.h>
using namespace std;
int cnt,want;
main(){
    cin >> want;
    while(true){
        int x;
        cin >> x;
        if(x == 0)
            break;
        if(want == x)
            cnt++;
    }
    if(cnt == 0)
        cout << "None";
    else
        cout << cnt;
}
