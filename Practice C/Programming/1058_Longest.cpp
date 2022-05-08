#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+100;
int t,n,m;
char a[N][N];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> n >> m;
        vector<vector<int>> row(n+1), col(m+1);
        for(int i=1; i<=n; i++)
            row[i].emplace_back(0);
        for(int i=1; i<=m; i++)
            col[i].emplace_back(0);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin >> a[i][j];
                if(a[i][j] == '0'){
                    row[i].emplace_back(j);
                    col[j].emplace_back(i);
                }
            }
        }
        for(int i=1; i<=n; i++)
            row[i].emplace_back(m+1);
        for(int i=1; i<=m; i++)
            col[i].emplace_back(n+1);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(a[i][j] == '0')
                    continue;
                int up = col[j][(lower_bound(col[j].begin(), col[j].end(), i)-col[j].begin())-1];
                int down = col[j][(upper_bound(col[j].begin(), col[j].end(), i)-col[j].begin())];
                int lef = row[i][(lower_bound(row[i].begin(), row[i].end(), j)-row[i].begin())-1];
                int rig = row[i][(upper_bound(row[i].begin(), row[i].end(), j)-row[i].begin())];
                up = i-up, down = down-i, lef = j-lef, rig = rig-j;
                ans = max(ans, max({up+lef, up+rig, down+lef, down+rig})-1);
                //cout << "Idx : " << i << " " << j << "\tANS: " << ans << "\n";
                //cout << "U :" << up << " D: " << down << " L: " << lef << " R: " << rig << "\n";
            }
        }
        cout << ans << "\n";
    }
}
