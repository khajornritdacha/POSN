#include<bits/stdc++.h>
using namespace std;

const int N = 3e2+10;
int R,C,a[N][N],pos,neg,ev,od;

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
        if(r < 1 or r > R or c < 1 or c > C) continue;

        if(a[r][c]%2 == 0){
            ev++;
        }else{
            od++;
        }

        if(a[r][c] > 0){
            pos++;
        }else if(a[r][c] < 0){
            neg++;
        }
    }

    cout << pos << " " << neg << " " << ev << " " << od << "\n";
}
