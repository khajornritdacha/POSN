#include<bits/stdc++.h>
using namespace std;
int y,cnt,x;
bool ok;
main(){
    cin >> x >> y;
    if(x>y)
        swap(x,y);
    for(int i=1; i<=8; i++){
        int z;
        cin >> z;
        if(x <= z and z <= y){
            cnt++;
        }
    }
    if(!cnt)
        cout << "None";
    else
        cout << cnt;
}
