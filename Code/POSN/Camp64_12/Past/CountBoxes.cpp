#include<bits/stdc++.h>
using namespace std;
int n,a[5],cnt[5],ans[5];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        int sz = a[0]*a[1]*a[2];
        if(a[0] <= 8 and a[1] <= 10 and a[2] <= 15){
            cout << 1;
            cnt[0]++;
            ans[0]+=(8*10*15)-sz;
        }else if(a[0] <= 12 and a[1] <= 15 and a[2] <= 25){
            cout << 2;
            cnt[1]++;
            ans[1]+=(12*15*25)-sz;
        }else if(a[0] <= 20 and a[1] <=40 and a[2] <= 50){
            cout << 3;
            cnt[2]++;
            ans[2]+=(20*40*50)-sz;
        }else{
            cout << "Oversize product";
        }
        cout << "\n";
    }
    for(int i=0; i<3; i++){
        cout << cnt[i] << " " << ans[i] << "\n";
    }
}
