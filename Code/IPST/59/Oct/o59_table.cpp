#include<bits/stdc++.h>
using namespace std;
int R,C,M,seg[310][20010],lim;
void up(int r, int c, int x){
    c+=C-1;
    seg[r][c] = x;
    for(c/=2; c; c/=2){
        int a = 2e9,b=2e9;
        if(2*c <= lim)
            a = seg[r][2*c];
        if(2*c+1 <= lim)
            b = seg[r][2*c+1];
        seg[r][c] = min(a,b);
    }
}
int qq(){
    int ans = 1e9;
    for(int i=1; i<=R; i++){
        ans = min(ans, seg[i][1]);
    }
    return ans;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> M;
    lim = 2*C-1;
    for(int i=1; i<=M; i++){
        int K,r,c,x;
        cin >> K;
        if(K == 1){
            cin >> r >> c >> x;
            up(r,c,x);
        }else if(K == 2){
            cin >> r >> x;

            for(int i=1; i<=lim; i++)
                seg[r][i] = x;
        }else if(K == 3){
            cin >> r >> c;
            cout << seg[r][C+c-1] << "\n";
        }else if(K == 4){
            cout << qq() << "\n";
        }
    }
}
