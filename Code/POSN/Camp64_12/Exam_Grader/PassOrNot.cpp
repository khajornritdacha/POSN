#include<bits/stdc++.h>
using namespace std;
int n,a[10],cnt;
main(){
    for(int i=1; i<=4; i++){
        cin >> a[i];
    }
    for(int i=1; i<=4; i++){
        int x;
        cin >> x;
        if(x >= a[i]){
            cout << i << " ";
            cnt++;
        }
    }
    if(cnt == 0)
        cout << "0";
    cout << "\n";
    if(cnt >= 3)
        cout << "pass";
    else
        cout << "fail";
}
