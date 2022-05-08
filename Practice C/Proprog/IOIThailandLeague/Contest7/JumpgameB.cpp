#include<bits/stdc++.h>
using namespace std;

const int N = 2e2+10;
int n,m,K,L,C,mod=6,a[N][N],dis[6][N][N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> K >> L >> C;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    for(int i=0; i<6; i++) for(int j=0; j<m; j++) for(int k=0; k<=K+1; k++) dis[i][j][k] = 1e9;

    for(int i=0; i<n; i++){
        int cur = i%mod;

        if(i == n-1){
            int mn = 1e9,use;
            for(int k=0; k<=K; k++){
                if(dis[cur][C][k] + k < mn){
                    mn = dis[cur][C][k]+k;
                    use = k;
                }
            }
            cout << mn << " " << use << "\n";
            return 0;
        }

        if(i == 0)
            dis[cur][L][0] = 0;

        for(int j=0; j<m; j++){
            int gr = (i+a[i][j])%mod;
            for(int k=0; k<=K; k++){
                if(j+a[i][j] < m)
                    dis[gr][j+a[i][j]][k] = min(dis[gr][j+a[i][j]][k], dis[cur][j][k]+1);
                if(j-a[i][j] >= 0)
                    dis[gr][j-a[i][j]][k] = min(dis[gr][j-a[i][j]][k], dis[cur][j][k]+1);
                dis[gr][j][k+1] = min(dis[gr][j][k+1], dis[cur][j][k]);
                dis[cur][j][k] = 1e9;
            }
        }

    }
}
