#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
char a[N][N];
int n,mr,mc,lr,lc,T=5000;

void solve(int lv=1){
    if(lv == n+1){
        return;
    }

    if(lv == 1){
        a[T][T] = 'A';
        solve(lv+1);
        return;
    }

    int sr,sc,pr,pc;

    if((lv-2)%4 == 0){
        sr = lr, sc = mc+1;
        pr = 1, pc = 1;
    }else if((lv-2)%4 == 1){
        sr = mr+1, sc = lc;
        pr = 1, pc = 1;
    }else if((lv-2)%4 == 2){
        sr = lr, sc = lc-1;
        pr = 1, pc = -1;
    }else if((lv-2)%4 == 3){
        sr = lr-1, sc = mc;
        pr = -1, pc = -1;
    }

    int sz = max(mr-lr+1, mc-lc+1);

    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            a[T+sr+i*pr][T+sc+j*pc] = lv+'A'-1;
            mr = max(mr, sr+i*pr), mc = max(mc, sc+j*pc);
            lr = min(lr, sr+i*pr), lc = min(lc, sc+j*pc);
        }
    }

    solve(lv+1);
}
main(){
    cin >> n;
    solve();

    for(int i=lr; i<=mr; i++){
        for(int j=lc; j<=mc; j++){
            cout << a[T+i][T+j];
        }
        cout << "\n";
    }
}
