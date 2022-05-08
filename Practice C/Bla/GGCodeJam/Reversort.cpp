#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 1e2+10;
int a[N],n;
void TC(){
    int ans = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<n; i++){
        int k = 0, mn=1e9,len;
        for(int j=i; j<=n; j++){
            if(a[j] < mn){
                mn = a[j];
                k = j;
            }
        }
        len = k-i+1;
        for(int j=0; j<len/2; j++){
            swap(a[i+j], a[i+len-j-1]);
        }
        //cout << "IDX : " << i << " " << mn << " " << k << "\n";
        if(DEBUG){
            for(int j=1; j<=n; j++){
                cout << a[j] << " \n"[j==n];
            }
        }
        ans += k-i+1;
    }
    cout << ans << "\n";
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    for(int te=1; te<=t; te++){
        cout << "Case #" << te << ": ";
        TC();
    }
}
