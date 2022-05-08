#include<bits/stdc++.h>
using namespace std;
int x,y,ans[5];
main(){
    cin >> x >> y;
    while(true){
        int z;
        cin >> z;
        if(z <= 0)
            break;
        if(z%x == 0 and z%y!=0)
            ans[0]+=z;
        else if(z%y == 0 and z%x!=0)
            ans[1]+=z;
        if(z%x == 0 or z%y == 0)
            ans[2]+=z;
    }
    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
}
