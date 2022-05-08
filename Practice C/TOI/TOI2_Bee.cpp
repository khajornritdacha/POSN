#include<bits/stdc++.h>
using namespace std;
int t[30],w[30];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    w[1] = 2;
    t[1] = 1;
    for(int i=2;i<=25;i++){
        w[i] = t[i-1]+w[i-1]+1;
        t[i] = w[i-1];
    }
    while(true){
        int x;
        cin >> x;
        if(x==-1)
            return 0;
        cout << w[x] << " " << w[x]+t[x]+1 << "\n";
    }
}
