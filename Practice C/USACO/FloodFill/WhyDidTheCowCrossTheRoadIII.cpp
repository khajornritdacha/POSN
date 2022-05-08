#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 1e2+10;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

int cnt,n,K,R,pr[]={-1,1,0,0},pc[]={0,0,-1,1},a[N][N],ans,sum;
bool vi[N][N];
vector<pi> ro[N][N];

void chk(int ssr, int ssc){
    queue<pi> qq;
    qq.emplace(ssr, ssc);
    while(!qq.empty()){
        auto [nr, nc] = qq.front();
        qq.pop();

        if(DEBUG){
            printf("%d %d\n", nr, nc);
        }

        vi[nr][nc] = true;
        cnt += a[nr][nc];
        for(int i=0; i<4; i++){
            int gr = nr+pr[i], gc = nc+pc[i];
            if(gr < 1 or gr > n or gc < 1 or gc > n) continue;
            if(find(ro[nr][nc].begin(), ro[nr][nc].end(), pi(gr, gc)) != ro[nr][nc].end()) continue;
            if(vi[gr][gc]) continue;
            vi[gr][gc] = true;
            qq.emplace(gr, gc);
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); freopen("countcross.in", "r", stdin); freopen("countcross.out", "w", stdout);
    cin >> n >> K >> R;
    for(int i=1; i<=R; i++){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        ro[r1][c1].emplace_back(r2, c2);
        ro[r2][c2].emplace_back(r1, c1);
    }
    for(int i=1; i<=K; i++){
        int r1,c1;
        cin >> r1 >> c1;
        a[r1][c1]++;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(vi[i][j]) continue;

            if(DEBUG){
                printf("Start : %d %d\n", i, j);
            }

            cnt = 0;
            chk(i, j);
            ans += sum*cnt;
            sum += cnt;
        }
    }
    cout << ans << "\n";
}
