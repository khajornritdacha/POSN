#include<bits/stdc++.h>
using namespace std;
int n,now=1;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        if(x > now){
            if(x-now > 10){
                for(int j=now; j<now+3; j++){
                    cout << j << " ";
                }
                cout << ". . . ";
                for(int j=x-2; j<=x; j++){
                    cout << j << " ";
                }
            }else{
                for(int j=now; j<=x; j++){
                    cout << j;
                    if(j!=x)
                        cout << " ";
                }
            }
        }else if(x < now){
            if(now-x > 10){
                for(int j=now; j>=now-2; j--){
                    cout << j << " ";
                }
                cout << ". . . ";
                for(int j=x+2; j>=x; j--){
                    cout << j << " ";
                }
            }else{
                for(int j=now; j>=x; j--){
                    cout << j;
                    if(j!=x)
                        cout << " ";
                }
            }
        }
        if(i!=n)
            cout << "\n";
        now = x;
    }
}
