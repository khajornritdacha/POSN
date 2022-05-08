#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,a[N],mx,K;
main(){
    cin >> n >> K;
    for(int i=1; i<=K; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i=1; i<=n; i++){
        if(a[i] > a[mx])
            mx = i;
    }
    cout << mx << "\n" << a[mx];
}
