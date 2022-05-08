#include<bits/stdc++.h>
using namespace std;
string str;
int K,lx,ly,cntx[2],cnty[2],ans;
int cal(int num, int code){
    if(code)
        return num*-1;
    return num;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> str >> K;
    for(int i=0; i<str.size(); i++){
        if(str[i] == 'N'){
            cnty[0]++;
            ly++;
        }else if(str[i] == 'S'){
            cnty[1]++;
            ly--;
        }else if(str[i] == 'W'){
            cntx[1]++;
            lx--;
        }else if(str[i] == 'E'){
            cntx[0]++;
            lx++;
        }
    }
    //cout << "Last : " << lx << " " << ly << "\n";
    for(int bit=0; bit<4; bit++){
        int x = ((bit&2)!=0);
        int y = bit&1;
        int now = K;
        int ty,tx;
        //cout << "HERE : " << x << " " << y << " " << now << "\n";
        if(now >= cnty[y]){
            ty = ly-cal(cnty[y], y);
            now-=cnty[y];
        }else{
            ty = ly-cal(now, y);
            now = 0;
        }
        if(now >= cntx[x]){
            tx = lx-cal(cntx[x], x);
            now-=cntx[x];
        }else{
            tx = lx-cal(now, x);
            now = 0;
        }
        if(now > 0){
            if(now >= cntx[!x]){
                tx -= cal(cntx[!x], !x);
                now -= cntx[!x];
            }else{
                tx -= cal(now, !x);
                now = 0;
            }
        }
        //cout << "TX : " << tx << "\n";
        //cout << "TY : " << ty << "\n";
        if(now > 0){
            if(now >= cnty[!y]){
                ty -= cal(cnty[!y], !y);
                now -= cnty[!y];
            }else{
                ty -= cal(now, !y);
                now = 0;
            }
        }
        /*cout << "NOW : " << now << "\n";
        cout << "X : " << (x == 0 ? "E" : "W") << " " << tx << "\n";
        cout << "Y : " << (y == 0 ? "N" : "S") << " " << ty << "\n";*/
        ans = max(ans, (abs(tx)+abs(ty))*2);
    }
    cout << ans;
}
