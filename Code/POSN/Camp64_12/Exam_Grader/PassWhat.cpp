#include<bits/stdc++.h>
using namespace std;
int n,a[10];
main(){
    for(int i=1; i<=4; i++){
        cin >> a[i];
    }
    for(int i=1; i<=4; i++){
        int x;
        cin >> x;
        if(x >= a[i])
            cout << i << " ";
    }
}
