#include<bits/stdc++.h>
using namespace std;
int cnt[5],lo[5],sc[5];
int a,b,x,y;
main(){
    for(int i=1; i<=6; i++){
        cin >> a >> b >> x >> y;
        cnt[a]+=x;
        lo[a]+=y;
        cnt[b]+=y;
        lo[b]+=x;
        if(x == y){
            sc[a]++;
            sc[b]++;
        }else if(x > y){
            sc[a]+=3;
        }else if(y > x){
            sc[b]+=3;
        }
    }
    for(int i=1; i<=3; i++){
        cout << sc[i] << " " << cnt[i] << " " << lo[i] << "\n";
    }
}
