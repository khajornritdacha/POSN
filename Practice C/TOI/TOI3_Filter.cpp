#include<bits/stdc++.h>
using namespace std;
int W,H,n,ep[3050],ze,on;
main(){
    cin >> W >> H >> n;
    for(int i=1; i<=n; i++){
        int x,a;
        cin >> x >> a;
        ep[x+1]++;
        ep[min(x+a+1, 3001)]--;
    }
    for(int i=1; i<=W; i++){
        ep[i]+=ep[i-1];
        //cout << ep[i] << " \n"[i==W];
        if(ep[i] == 0)
            ze++;
        else if(ep[i] == 1)
            on++;
    }
    cout << ze*H << " " << on*H;
}
