#include<bits/stdc++.h>
using namespace std;

int n,a[110];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        cout << max(x, a[i])*10+min(x, a[i]) << " ";
    }
}
