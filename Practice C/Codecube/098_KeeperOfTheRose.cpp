#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using pi = pair<int,int>;
int n,M,a[N],b[N],ans;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    for(int i=1; i<=M; i++){
        int x;
        cin >> x;
        if(i >= b[x]){
            ans++;
            b[x] = i+a[x];
        }
    }
    cout << ans;
}
