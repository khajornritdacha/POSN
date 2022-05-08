#include<bits/stdc++.h>
using namespace std;

int n,a[10010],mx;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    mx = *max_element(a+1, a+10002);
    for(int i=1; i<=10000; i++){
        if(a[i] == mx)
            cout << i << " ";
    }
}
