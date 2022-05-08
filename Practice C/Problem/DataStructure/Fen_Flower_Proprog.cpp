#include<bits/stdc++.h>
using namespace std;
int n,fen[100010],ans,track[100010];
void up(int i, int val){
    while(i<=100000){
        fen[i] += val;
        i+=(i&-i);
    }
}
int qs(int i){
    int sum = 0;
    while(i>0){
        sum+=fen[i];
        i-=i&-i;
    }
    return sum;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        ans = 0;
        int tmp = qs(x);
        tmp -= track[x];
        track[x] += tmp;
        //cout << "x: " << tmp << "\n";
        ans += tmp;
        tmp = qs(y);
        tmp -= track[y];
        track[y] += tmp;
        ans += tmp;
        //cout << "y: " << qs(y) << " " << track[y] << " " << tmp << "\n";
        //cout << "QS: " << qs(6) << "\n";
        /*for(int i=1; i<=10; i++){
            cout << qs(i) << " \n"[i==10];
        }*/
        up(x+1, 1);
        up(y, -1);
        cout << ans << "\n";
    }
}
///https://www.proprog.ml/tasks/flower/descs/7411
