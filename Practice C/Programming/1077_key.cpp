#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
int n,m,qs[1005][1005];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        qs[++x][++y]++;
    }
    for(int i=1; i<=1002; i++){
        for(int j=1; j<=1002; j++){
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    /*for(int i=1; i<=11; i++){
        for(int j=1; j<=11; j++){
            cout << qs[i][j] << " ";
        }
        cout << '\n';
    }*/
    while(m--){
        int x,y,k;
        cin >> x >> y >> k;
        x++;
        y++;
        int xm=x+k;
        int ym=y+k;
        int xi=x-k-1;
        int yi=y-k-1;
        if(x+k>=1002)
            xm=1002;
        if(y+k>=1002)
            ym=1002;
        if(x-k-1<0)
            xi=0;
        if(y-k-1<0)
            yi=0;
        cout << qs[xm][ym]-qs[xm][yi]-qs[xi][ym]+qs[xi][yi] << "\n";
    }
}

