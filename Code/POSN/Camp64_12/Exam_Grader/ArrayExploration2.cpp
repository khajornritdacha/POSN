#include<bits/stdc++.h>
using namespace std;

const int N = 3e2+10;
int R,C,a[N][N],pos,neg,ev,od;
bool lp,ln,lo,le;

main(){
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> a[i][j];
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int r,c;
        cin >> r >> c;
        if(r < 1 or r > R or c < 1 or c > C){
            if(le)
                ev++;
            if(lo)
                od++;
            if(lp)
                pos++;
            if(ln)
                neg++;
            continue;
        }

        le = lo = lp = ln = false;

        if(a[r][c]%2 == 0){
            le = true;
            ev++;
        }else{
            lo = true;
            od++;
        }

        if(a[r][c] > 0){
            lp = true;
            pos++;
        }else if(a[r][c] < 0){
            ln = true;
            neg++;
        }
    }

    cout << pos << " " << neg << " " << ev << " " << od << "\n";
}
