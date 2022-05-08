#include<bits/stdc++.h>
using namespace std;
int ans=1e9,x;
main(){
    cin >> x;
    for(int i=1; i<=8; i++){
        int y;
        cin >> y;
        if(abs(x-y) < abs(x-ans))
            ans = y;
    }
    cout << ans;
}
