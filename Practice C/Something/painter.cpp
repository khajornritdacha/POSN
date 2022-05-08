#include<bits/stdc++.h>
using namespace std;
int r,c,ft[55][55],t[55][55],code=0;
pair <int,int> st,den,bt[55][55];
vector < pair<int,int> > fld;
char ipt[55][55];
bool visit[55][55];
queue< pair<int,int> > qq;
void pans(int x,int y){
    if(x==st.first&&y==st.second)
        return;
    pans(bt[x][y].first,bt[x][y].second);
    cout << x << " " << y << '\n';
    return;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> ipt[i][j];
            ft[i][j] = 1e9;
            if(ipt[i][j]=='S'){
                st.first = i;
                st.second = j;
            }
            if(ipt[i][j]=='*'){
                fld.emplace_back(i,j);
            }
        }
    }
    for(int x=0;x<fld.size();x++){
        int nr = fld[x].first;
        int nc = fld[x].second;
        ft[nr][nc] = 0;
        int xx[] = {0,-1,1,0},yy[] = {-1,0,0,1};
        qq.emplace(nr,nc);
        while(!qq.empty()){
            int row = qq.front().first;
            int col = qq.front().second;
            qq.pop();
            for(int i=0;i<4;i++){
                if(row+xx[i]<1||row+xx[i]>r||col+yy[i]<1||col+yy[i]>c)
                    continue;
                if(ipt[row+xx[i]][col+yy[i]]=='X')
                    continue;
                if(ft[row][col]+1<ft[row+xx[i]][col+yy[i]]){
                    qq.emplace(row+xx[i],col+yy[i]);
                    ft[row+xx[i]][col+yy[i]] = ft[row][col]+1;
                }
            }
        }
    }
    qq.emplace(st.first,st.second);
    t[st.first][st.second] = 0;
    while(!qq.empty()){
        int nr = qq.front().first;
        int nc = qq.front().second;
        qq.pop();
        int xx[] = {0,-1,1,0},yy[] = {-1,0,0,1};
        visit[nr][nc] = true;
        if(ipt[nr][nc]=='D'){
            cout << t[nr][nc] << '\n';
            den.first = nr;
            den.second = nc;
            code = 1;
            break;
        }
        for(int i=0;i<4;i++){
            int nowr = nr+xx[i];
            int nowc = nc+yy[i];
            if(nowr<1||nowr>r||nowc<1||nowc>c)
                continue;
            if(ipt[nowr][nowc]=='X')
                continue;
            if(visit[nowr][nowc]==true)
                continue;
            if(t[nowr][nowc]<ft[nowr][nowc]||ipt[nowr][nowc]=='D'){
                qq.emplace(nowr,nowc);
                t[nowr][nowc] = t[nr][nc]+1;
                if(bt[nowr][nowc].first==0&&bt[nowr][nowc].second==0){
                    bt[nowr][nowc].first = nr;
                    bt[nowr][nowc].second = nc;
                }
            }
        }
    }

        /*for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cout << ft[i][j];
            }
            cout << '\n';
        } */
        /*for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cout << t[i][j];
            }
            cout << '\n';
        }*/
    if(code==1)
        pans(den.first,den.second);
    if(code==0)
        cout << "KAKTUS";
return 0;
}
