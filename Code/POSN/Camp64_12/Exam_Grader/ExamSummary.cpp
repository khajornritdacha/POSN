#include<bits/stdc++.h>
using namespace std;
int n,a[10],cou[10];
main(){
    for(int i=1; i<=4; i++){
        cin >> a[i];
    }
    cin >> n;
    for(int j=1; j<=n; j++){
        int cnt = 0;
        for(int i=1; i<=4; i++){
            int x;
            cin >> x;
            if(x >= a[i]){
                cnt++;
                cou[i]++;
            }
        }
        if(cnt >= 3){
            cout << "pass\n";
            cou[0]++;
        }else{
            cout << "fail\n";
        }
    }
    cout << cou[0] << "\n";
    for(int i=1; i<=4; i++)
        cout << cou[i] << " ";
}
