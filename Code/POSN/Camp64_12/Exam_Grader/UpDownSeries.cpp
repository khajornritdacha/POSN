#include<bits/stdc++.h>
using namespace std;
int a,b,c,sum;
bool code = false;
main(){
    cin >> a >> b >> c;
    int now = a;
    while(true){
        sum += now;
        if(!code and now*c > b)
            code = true;
        if(code)
            now/=c;
        else
            now*=c;
        if(code and now < a)
            break;
    }
    cout << sum << "\n";
}
