#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int V,e[11],mn=10,dmx,num,dzero,ans[N];

main(){
    e[10] = 1e9;
    cin >> V;
    for(int i=0; i<=9; i++){
        cin >> e[i];
    }

    for(int i=9; i>=0; i--){
       // cout << i << " " << e[i] << " " << V/e[i] << "\n";
        if(i!=0 and V/e[i] > dmx){
            dmx = V/e[i];
            num = i;
        }
        if(i > 0 and e[i] < e[mn])
            mn = i;
    }

    dzero = (V-e[mn])/e[0];
    //cout << mn << " " << dzero << "\n";
    if(dzero > dmx){
        dmx = dzero+1;
        ans[1] = mn;
        V -= e[mn];
        for(int i=2; i<=dmx; i++){
            ans[i] = 0;
            V -= e[0];
        }
    }else{
        for(int i=1; i<=dmx; i++){
            ans[i] = num;
            V -= e[num];
        }
    }

    for(int i=1; i<=dmx; i++){
        for(int j=9; j>=0; j--){
            if(i == 1 and j == 0) continue;
            if(j > ans[i] and V+e[ans[i]]-e[j] >= 0){
                V += e[ans[i]]-e[j];
                ans[i] = j;
            }
        }
    }

    if(dmx == 0){
        cout << "-1";
    }else{
        for(int i=1; i<=dmx; i++){
            cout << ans[i];
        }
    }
}
