#include<bits/stdc++.h>
using namespace std;
int in,si,io,se;
main(){
    while(true){
        int x,y;
        cin >> x;
        if(x == 0)
            break;
        cin >> y;
        if(x == 1){
            in++;
            si+=y;
        }else{
            io++;
            se+=y;
        }
    }
    cout << in << " " << io << "\n" << si << " " << se << " " << si-se;
}
