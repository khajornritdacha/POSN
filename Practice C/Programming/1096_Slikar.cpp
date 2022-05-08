#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 5e2+13;
int qs[N][N],n,pr[]={0,0,1,1},pc[]={0,1,0,1},dp[11][N][N],bb[11];
char a[N][N];
bool vi[11][N][N];
int gs(int nr, int nc, int r, int c){
    //cout << nr << " " << nc << " " << r << " " << c << " = " << qs[nr][nc]-qs[nr][c-1]-qs[r-1][nc]+qs[r-1][c-1] << "\n";
    return qs[nr][nc]-qs[nr][c-1]-qs[r-1][nc]+qs[r-1][c-1];
}
int solve(int sz, int r, int c){
    //cout << sz << " " << r << " " << c << "\n";
    if(sz == 1)
        return 0;
    int bit = sz&-sz;
    if(vi[bb[bit]][r][c])
        return dp[bb[bit]][r][c];
    vi[bb[bit]][r][c] = true;
    int mn = 1e9;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(i == j) continue;
            int tmp = gs(r+sz/2*(pr[i]+1)-1, c+sz/2*(pc[i]+1)-1, r+sz/2*pr[i], c+sz/2*pc[i])+(sz/2*sz/2)-gs(r+sz/2*(pr[j]+1)-1, c+sz/2*(pc[j]+1)-1, r+sz/2*pr[j], c+sz/2*pc[j]);
            for(int k=0; k<4; k++){
                if(k != i and k!= j)
                    tmp+=solve(sz/2, r+sz/2*pr[k], c+sz/2*pc[k]);
            }
            if(DEBUG and sz == 4){
                cout << "NOW : " << sz << " " << r << " " << c << "\n";
                cout << "I&J : " << i << " " << j << " = ";
                cout << tmp << "\n\n";
            }
            mn = min(mn, tmp);
        }
    }
    return dp[bb[bit]][r][c] = mn;
}
main(){
    for(int i=0; i<=10; i++){
        bb[(1<<i)] = i;
    }
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            qs[i][j] = (a[i][j]-'0')+qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    cout << solve(n, 1 ,1);
}
