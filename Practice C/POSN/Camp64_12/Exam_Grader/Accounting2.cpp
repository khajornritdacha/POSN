#include<bits/stdc++.h>
using namespace std;
int x,y,sum;
main(){
    while(true){
        cin >> x >> y;
        if(x == 0 and y == 0)
            break;
        if(x == 1)
            sum+=y;
        else
            sum-=y;
    }
    if(sum >= 0)
        cout << "Good";
    else
        cout << "Bad";
    cout << "\n" << abs(sum);
}
