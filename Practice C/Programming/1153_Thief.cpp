#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int>;

int n,dp[N][N];
vector<tu> vec;
vector<int> st,ed,pr;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1,p,k,v; i<=n; i++){
        cin >> p >> k >> v;
        vec.emplace_back(p, k, v);
    }
    sort(vec.begin(), vec.end());
    st.resize(n+1, 0), ed.resize(n+1, 0), pr.resize(n+1, 0);
    for(int i=0; i<vec.size(); i++){
        tie(st[i+1], ed[i+1], pr[i+1]) = vec[i];
    }

    for(int i=n; i>=1; i--){
        for(int e=0; e<=1e3; e++){
            dp[i][e] = dp[i+1][e];
            if(e == 0){
                dp[i][e] = max(dp[i][e], pr[i]+dp[i+1][ed[i]]);
            }else{
                if(st[i] >= e){
                    dp[i][e] = max(dp[i][e], pr[i]+dp[i+1][ed[i]]); ///same as dp[i][0]
                }else if(ed[i] >= e){
                    int k = lower_bound(st.begin(), st.end(), e)-st.begin();
                    dp[i][e] = max(dp[i][e], pr[i]+dp[k][ed[i]]);
                }else if(ed[i] < e){
                    int k = lower_bound(st.begin(), st.end(), ed[i])-st.begin();
                    dp[i][e] = max(dp[i][e], pr[i]+dp[k][e]);
                }
            }
        }
    }
    cout << dp[1][0] << "\n";
}
