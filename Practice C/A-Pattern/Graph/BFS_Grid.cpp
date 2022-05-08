#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
int pr[]={-1,0,1,0},pc[]={0,1,0,-1},R,C,str,stc,edr,edc,dis[N][N];
char ta[N][N];
bool vi[N][N];


main(){
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> ta[i][j];
        }
    }
    cin >> str >> stc;
    cin >> edr >> edc;
    queue<pair<int,int>> qq;
    qq.push({str, stc});
    vi[str][stc] = true;
    while(!qq.empty()){
        int nr,nc;
        tie(nr, nc) = qq.front();
        qq.pop();
        for(int i=0; i<4; i++){
            int go_r = nr+pr[i], go_c = nc+pc[i];
            if(go_r < 1 or go_r > R or go_c < 1 or go_c > C)
                continue;
            if(ta[go_r][go_c] == '#')
                continue;
            if(vi[go_r][go_c] == true)
                continue;
            vi[go_r][go_c] = true;
            dis[go_r][go_c] = dis[nr][nc]+1;
            qq.push({go_r, go_c});
        }
    }
    cout << dis[edr][edc] << "\n";
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout << dis[i][j] << " ";
        }
        cout << "\n";
    }
}
/*
4 7
..#.#..
....#..
......#
.....#.
3 2
1 7
*/
