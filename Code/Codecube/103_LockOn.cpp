#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+100;
int n,P,ep[N],mn=1e9;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> P;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        if(x > y)
            swap(x,y);
        ep[x]++;
        ep[y+1]--;
    }

    for(int i=0; i<=1e6+10; i++){
        if(i != 0)
            ep[i] += ep[i-1];
        if(ep[i] == n){
            mn = min(mn, abs(P-i));
        }
    }

    if(mn == 1e9)
        mn = -1;

    cout << mn << "\n";
}
