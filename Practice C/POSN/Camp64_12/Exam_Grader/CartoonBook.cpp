#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int n,a[N],pos[5],mn[5],b[N];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    mn[1]=mn[2]=mn[3]=1e9;
    for(int i=1; i<=n; i++){
        cin >> b[i];
        if(mn[a[i]] > b[i]){
            mn[a[i]] = b[i];
            pos[a[i]] = i;
        }
    }
    if(mn[1]+mn[2] <= mn[3]){
        cout << pos[1] << " " << pos[2] << " " << b[pos[1]]+b[pos[2]];
    }else{
        cout << pos[3] << " " << pos[3] << " " << b[pos[3]];
    }
}
