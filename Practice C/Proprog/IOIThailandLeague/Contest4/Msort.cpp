#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,ans,a[N];
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<n; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                ans++;
            }
        }
    }
    cout << ans*2;
}
