#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+10;
int n,K,idx=0,pa[N];
int fi(int x){
    if(pa[x] == x)
        return x;
    return pa[x] = fi(pa[x]);
}
void uni(int u){
    int v = fi((u+1)%n);
    pa[u] = pa[v];
}
main(){
    cin >> n >> K;
    for(int i=0; i<n; i++){
        pa[i] = i;
    }
    for(int i=1; i<=n; i++){
        int tmp = (K-1)%(n-i+1), cnt = 0;
        while(true){
            if(cnt >= tmp)
                break;
            idx = fi(idx+1);
            cnt++;
        }
        cout << idx+1 << "\n";
        uni(idx);
        idx = fi(idx);
    }
}
