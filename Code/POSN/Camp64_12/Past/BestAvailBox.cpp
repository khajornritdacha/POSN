#include<bits/stdc++.h>
using namespace std;
int n,a[5],cnt[5],num[5];

main(){
    cin >> n >> num[0] >> num[1] >> num[2];
    for(int i=1; i<=n; i++){
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        int sz = a[0]*a[1]*a[2];
        if(a[0] <= 20 and a[1] <=40 and a[2] <= 50){
            if(num[0] > 0 and a[0] <= 8 and a[1] <= 10 and a[2] <= 15){
                cout << 1;
                cnt[0]++;
                num[0]--;
            }else if(num[1] > 0 and a[0] <= 12 and a[1] <= 15 and a[2] <= 25){
                cout << 2;
                cnt[1]++;
                num[1]--;
            }else if(num[2] > 0 and a[0] <= 20 and a[1] <=40 and a[2] <= 50){
                cout << 3;
                cnt[2]++;
                num[2]--;
            }else{
                cout << "Box not available";
            }
        }else{
            cout << "Oversize product";
        }
        cout << "\n";
    }
}
