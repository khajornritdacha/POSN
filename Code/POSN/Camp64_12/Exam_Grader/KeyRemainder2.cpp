#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int a[N],key,n,want;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        int x;
        cin >> x;
        if(x == 0)
            break;
        a[n++] = x;
    }
    cin >> key >> want;
    for(int i=0; i<n; i++){
        //cout << a[i] << " " << a[i]%key << "\n";
        if(a[i]%key == want){
            cout << a[i] << " ";
        }
    }
}
