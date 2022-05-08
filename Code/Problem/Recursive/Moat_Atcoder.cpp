#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

bool vi[15][15],tag[15][15];
int n,pr[]={-1,1,0,0},pc[]={0,0,-1,1},a[15][15],ans,all;

///https://atcoder.jp/contests/abc219/tasks/abc219_e

void dfs(int r, int c, int code){
    vi[r][c] = true;
    for(int i=0; i<4; i++){
        int gr = r+pr[i], gc = c+pc[i];
        if(gr < 1 or gr > 4 or gc < 1 or gc > 4) continue;
        if(vi[gr][gc] or (code ? tag[gr][gc] : !tag[gr][gc])) continue;
        dfs(gr, gc, code);
    }
}

bool check(){
    for(int i=1; i<=4; i++) for(int j=1; j<=4; j++) if(!tag[i][j] and a[i][j]) return false;
    for(int i=1; i<=4; i++) for(int j=1; j<=4; j++) vi[i][j] = false;
    int mnr,mnc,mxr,mxc, cmp = 0;
    mnr = mnc = 5;
    mxr = mxc = 0;
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            if(!vi[i][j] and tag[i][j]){
                if(++cmp > 1) return false;
                dfs(i, j, 0);
            }
        }
    }
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            if(i == 1 or i == n or j == 1 or j == n){
                if(!vi[i][j])
                    dfs(i, j, 1);
            }
        }
    }
    for(int i=1; i<=4; i++) for(int j=1; j<=4; j++) if(!tag[i][j] and !vi[i][j]) return false;
    return true;
}

void gen(int r, int c){
    if(c == 5){ r++, c = 1;}
    if(r == 5){
        if(check()){
            ans++;
            if(DEBUG){
                cout << "--------------------\n";
                for(int i=1; i<=4; i++){
                    for(int j=1; j<=4; j++){
                        cout << tag[i][j] << " ";
                    }
                    cout << "\n";
                }
                cout << "--------------------\n";
            }
        }
        return;
    }
    tag[r][c] = true;
    gen(r, c+1);
    tag[r][c] = false;
    gen(r, c+1);
}

int main(void){
    n = 4;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            all += a[i][j];
        }
    }
    gen(1, 1);
    cout << ans << "\n";
    return 0;
}
