#include<bits/stdc++.h>
using namespace std;

int a[3],cnt;

main(){
    cin >> a[0] >> a[1] >> a[2];
    //sort(a, a+2, greater<int>());
    while(a[0] > 1 or a[1] > 1 or a[2] > 1){
        sort(a, a+3, greater<int>());
        a[0]/=2;
        cnt++;
    }
    cout << cnt;
}
