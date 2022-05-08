#include<bits/stdc++.h>
#define DEBUG false
#define sz(x) (int)x.size()
using namespace std;
const int N = 1e3+10;
int n,m,w,cross[2],len[2],ans;
bool vi[N][N][2];
char a[N][N];
string str[N];
void chk(int r, int c, int code){
    if(code == 0){
        for(int i=r; i<=n; i++){
            if(a[i][c] != '.') break;
            len[code]++, vi[i][c][code]=1;
            if(a[i][c] == '.' and  (a[i][c+1] == '.' or a[i][c-1] == '.'))
                cross[code] = len[code];
        }
    }else{
        for(int j=c; j<=m; j++){
            if(a[r][j] != '.') break;
            len[code]++, vi[r][j][code]=1;
            if(a[r][j] == '.' and (a[r+1][j] == '.' or a[r-1][j] == '.'))
                cross[code] = len[code];
        }
    }
}
main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) cin >> a[i][j];
    cin >> w;
    for(int i=1; i<=w; i++){
        cin >> str[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == '.' and (a[i+1][j] == '.' or a[i-1][j] == '.') and !vi[i][j][0])
                chk(i, j, 0);
            if(a[i][j] == '.' and (a[i][j+1] == '.' or a[i][j-1] == '.') and !vi[i][j][1])
                chk(i, j, 1);
        }
    }
    if(DEBUG){
        cout << len[0] << " " << len[1] << " " << cross[0] << " " << cross[1] << "\n";
    }
    for(int i=1; i<=w; i++){
        for(int j=i+1; j<=w; j++){
            if(str[i].length() == len[0] and str[j].length() == len[1] and str[i][cross[0]-1] == str[j][cross[1]-1])
                ans++;
            if(str[i].length() == len[1] and str[j].length() == len[0] and str[i][cross[1]-1] == str[j][cross[0]-1])
                ans++;
        }
    }
    cout << ans << "\n";
}
