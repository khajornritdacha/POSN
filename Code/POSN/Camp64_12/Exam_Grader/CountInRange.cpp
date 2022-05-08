#include<bits/stdc++.h>
using namespace std;
int x,y,ans[5];
main(){
    cin >> x >> y;
    if(y < x)
        swap(x,y);
    while(true){
        int z;
        cin >> z;
        if(z == 0)
            break;
        if(x < z and z < y)
            ans[0]++;
        else if(z < x)
            ans[1]++;
        else if(z > y)
            ans[2]++;
    }
    cout << ans[0] << "\n" << ans[1] << "\n" << ans[2];
}
