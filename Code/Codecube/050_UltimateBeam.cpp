#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 2e5+10;
struct DATA{
    int st,ed;
};
int R,C,n,str,dp[2][2010][2];
DATA ro[N];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> n;
    for(int i=1; i<=n; i++){
        int c;
        cin >> c;
        cin >> ro[c].st >> ro[c].ed;
    }
    cin >> str;
    for(int i=0; i<2; i++) for(int j=0; j<=R; j++) dp[i][j][0] = dp[i][j][1] = 1e9;
    for(int i=1; i<=R; i++){
        dp[1][i][0] = abs(str-i);
    }

    int dq[2][2010];
    for(int i=2; i<=C; i++){
        int cur = i%2, pre = (i-1)%2;
        int sz[2]={0,0}, fi[2]={0,0};
        for(int l=0; l<2; l++){
            for(int r=1; r<=R; r++){
                dp[cur][r][l] = 1e9;
                if(dp[pre][r][l] == 1e9) continue;
                while(sz[l] > 0 and dp[pre][r][l]+r-1 <= dp[pre][dq[l][sz[l]-1]][l]+dq[l][sz[l]-1]-1)
                    sz[l]--;
                dq[l][sz[l]++] = r;
            }
        }
        for(int r=1; r<=R; r++){
            for(int l=0; l<2; l++){
                while(sz[l]-fi[l] > 1 and dp[pre][ dq[l][fi[l]+1] ][l]+abs(dq[l][fi[l]+1]-r) <= dp[pre][ dq[l][fi[l]] ][l]+abs(dq[l][fi[l]]-r))
                    fi[l]++;
            }
            int tmp[2];
            tmp[0] = dq[0][fi[0]]-r;
            tmp[1] = dq[1][fi[1]]-r;
            if(tmp[0] < 0) tmp[0] *= -1;
            if(tmp[1] < 0) tmp[1] *= -1;
            if(r >= ro[i].st and r <= ro[i].ed){
                if(sz[0] > 0)
                    dp[cur][r][1] = dp[pre][dq[0][fi[0]]][0]+tmp[0]+1;
            }else{
                if(sz[0] > 0)
                    dp[cur][r][0] = dp[pre][dq[0][fi[0]]][0]+tmp[0]+1;
                if(sz[1] > 0)
                    dp[cur][r][1] = dp[pre][dq[1][fi[1]]][1]+tmp[1]+1;
            }

        }

    }
    int ans = 1e9;
    for(int i=1; i<=R; i++)
        ans = min({ans, dp[C%2][i][0], dp[C%2][i][1]});
    cout << ans << "\n";
}
