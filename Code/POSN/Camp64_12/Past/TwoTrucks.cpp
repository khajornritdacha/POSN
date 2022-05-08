#include<bits/stdc++.h>
using namespace std;

main(){
    int n,a[2]={20000,20000};
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,res=0;
        cin >> x;
        if(a[0] >= x){
            a[0]-=x;
            res = 1;
        }else if(a[1] >= x){
            a[1]-=x;
            res = 2;
        }
        cout << res << "\n";
    }
}
