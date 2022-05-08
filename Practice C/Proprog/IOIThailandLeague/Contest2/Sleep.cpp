#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n,ep[N];
bool ok = true;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        ep[x]++;
        ep[y+1]--;
    }
    for(int i=1; i<=1e6; i++){
        ep[i]+=ep[i-1];
        if(ep[i] == n)
            ok = false;
    }
    if(ok)
        cout << "yes";
    else
        cout << "no";
}
