#include<bits/stdc++.h>
using namespace std;
int n,la=1;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x > la){
            if(x-la > 10){
                cout << la << " . . . " << x;
            }else{
                for(int j=la; j<=x; j++){
                    cout << j << " ";
                }
            }
        }else{
            if(la-x > 10){
                cout << la << " . . . " << x;
            }else{
                for(int j=la; j>=x; j--){
                    cout << j << " ";
                }
            }
        }
        cout << "\n";
        la = x;
    }
}
