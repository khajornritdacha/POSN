#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n,a[N];
long long ans1,ans2;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i+=2){
        ans1 += max(0, max(a[i+1], a[i-1])+1-a[i]);
    }
    for(int i=2; i<=n; i+=2){
        ans2 += max(0, max(a[i+1], a[i-1])+1-a[i]);
    }
    cout << min(ans1, ans2);
}
