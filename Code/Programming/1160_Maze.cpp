#include<bits/stdc++.h>
#define F first
#define S second
#define pii pair<int,int>
using namespace std;
bool visit[3][200][200];
int cnt[200][200],a[200][200],r,c,answay,ansdis=1e9,diss[200][200],dise[200][200];
queue<pii> qq;
set<pii> ps,pe;
pii st,ed;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    cin >> st.F >> st.S;
    cin >> ed.F >> ed.S;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
            diss[i][j] = 1e9;
            dise[i][j] = 1e9;
        }
    }
    diss[st.F][st.S] = 1;
    dise[ed.F][ed.S] = 1;
    qq.emplace(ed.F,ed.S);
    while(!qq.empty()){
        int row = qq.front().first;
        int col = qq.front().second;
        qq.pop();
        visit[0][row][col] = true;
        int pr[]={-1,0,0,1},pc[]={0,-1,1,0};
        for(int i=0;i<4;i++){
            int nr = row+pr[i];
            int nc = col+pc[i];
            if(nr<1||nc<1||nr>r||nc>c)
                continue;
            if(visit[0][nr][nc]==true)
                continue;
            if(a[nr][nc]==0){
                pe.insert({nr,nc});
            }
            visit[0][nr][nc] = true;
            dise[nr][nc] = dise[row][col]+1;
            if(a[nr][nc]==1)
                qq.emplace(nr,nc);
        }
    }
    qq.emplace(st.F,st.S);
    while(!qq.empty()){
        int row = qq.front().F;
        int col = qq.front().S;
        qq.pop();
        visit[1][row][col] = true;
        int pr[]={-1,0,0,1},pc[]={0,-1,1,0};
        for(int i=0;i<4;i++){
            int nr = row+pr[i];
            int nc = col+pc[i];
            if(nr<1||nc<1||nr>r||nc>c)
                continue;
            if(visit[1][nr][nc]==true)
                continue;
            if(a[nr][nc]==0){
                ps.insert({nr,nc});
            }
            visit[1][nr][nc] = true;
            diss[nr][nc] = diss[row][col]+1;
            if(a[nr][nc]==1){
                qq.emplace(nr,nc);
            }
        }
    }
    /*qq.emplace(st.F,st.S);
    while(!qq.empty()){
        int row = qq.front().F;
        int col = qq.front().S;
        qq.pop();
        visit[2][row][col] = true;
        int pr[]={-1,0,0,1},pc[]={0,-1,1,0};
        for(int i=0;i<4;i++){
            int nr = row+pr[i];
            int nc = col+pc[i];
            if(nr<1||nc<1||nr>r||nc>c)
                continue;
            if(visit[2][nr][nc]==true)
                continue;
            visit[2][nr][nc] = true;
            if(cnt[nr][nc]>=2||a[nr][nc]==1){
                qq.emplace(nr,nc);
                pa[nr][nc] = min(pa[nr][nc],pa[row][col]+1);
            }
        }
    }*/
    for(auto ss = ps.begin();ss!=ps.end();ss++){
        auto se = pe.find(*ss);
        if(se!=pe.end()){
            answay++;
            ansdis = min(ansdis,diss[ss->first][ss->second]+dise[se->first][se->second]-1);
        }
    }
    cout << answay << "\n";
    cout << ansdis << "\n";
    /*for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cout << dise[i][j] << " ";
        }
        cout << "\n";
    }*/
}
