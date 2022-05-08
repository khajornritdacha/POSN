#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+100;
int a[N],b[N],n,m,t;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--){
        int ans = 2e9,sum=0;
        vector<int> vec[2];
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        for(int i=1; i<=n; i++){
            cin >> b[i];
        }
        for(int i=1; i<=n; i++){
            if(b[i] == 1)
                vec[0].emplace_back(a[i]);
            else
                vec[1].emplace_back(a[i]);
        }
        sort(vec[0].rbegin(), vec[0].rend()), sort(vec[1].rbegin(), vec[1].rend());
        vec[0].insert(vec[0].begin(), 0), vec[1].insert(vec[1].begin(), 0);
        for(int j=0; j<=1; j++){
            for(int i=1; i<vec[j].size(); i++){
                vec[j][i]+=vec[j][i-1];
            }
        }
        for(int i=vec[0].size()-1, j=0; i>=0 and j<vec[1].size(); i--){
            while(j<vec[1].size() and vec[0][i]+vec[1][j] < m)
                j++;
            if(j>=vec[1].size())
                break;
            if(vec[0][i]+vec[1][j] >= m)
                ans = min(ans, i+(2*j));
        }
        if(ans == 2e9) ans=-1;
        cout << ans << "\n";
    }
}
///codeforces.com/problemset/problem/1475/D
