#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
int n,p[N];

int fi(int x){
    if(p[x] == x)
        return p[x];
    return p[x] = fi(p[x]);
}

void uni(int x){
    int hx = fi(x);
    if(hx == n){
        p[hx] = fi(1);
    }else{
        p[hx] = fi(hx+1);
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)
        p[i] = i;
    for(int i=1; i<=n; i++){
        int want;
        cin >> want;
        cout << fi(want) << " ";
        uni(want);
    }
}
