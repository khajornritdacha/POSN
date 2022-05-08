#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int ans;
main(){
    for(int i=0; i<3; i++){
        int x;
        cin >> x;
        while(x > 1){
            if(x%2)
                x--;
            x/=2;
            ans++;
        }
    }
    cout << ans << "\n";
}
