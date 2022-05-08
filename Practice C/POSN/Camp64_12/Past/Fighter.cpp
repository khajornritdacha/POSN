#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e6+10;
int n,a[N],hp[2];
main(){
    cin >> n;
    hp[1] = hp[0] = n;
    for(int i=1; i<=2*n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=2*n; i++){
        int cur = a[i]%2;
        if(i >= 3 and a[i-1]%2 == cur and a[i-2]%2 == cur){
            hp[!cur]-=3;
        }else{
            hp[!cur]--;
        }
        if(hp[0] <= 0){
            cout << 1 << endl << a[i];
            break;
        }
        if(hp[1] <= 0){
            cout << 0 << endl << a[i];
            break;
        }
    }
}
