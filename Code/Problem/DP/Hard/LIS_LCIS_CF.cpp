#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int n,m,a[N],b[N],pa[N],dp[N];
stack<int> st;

///https://codeforces.com/problemset/problem/10/D

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(int j = 1; j <= m; j++){
        cin >> b[j];
    }

    for(int i = 1; i <= n; i++){
        int mx = 0, pos = 0;
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j] and mx+1 > dp[j]){ //i-th can concatenate those who are less than a[i]
                dp[j] = mx+1;
                pa[j] = pos;
            }
            if(a[i] > b[j] and dp[j] > mx){ //track maximum of which less than a[i]
                mx = dp[j];
                pos = j;
            }
        }
    }

    ///backtracking
    int ans = 0, pos = 0;
    for(int j = 1; j <= m; j++){
        if(dp[j] > ans){
            ans = dp[j];
            pos = j;
        }
    }

    if(pos > 0){
        st.push(b[pos]);
        int cur = pa[pos];
        while(cur > 0){
            st.push(b[cur]);
            cur = pa[cur];
        }
    }

    cout << ans << "\n";
    while(!st.empty()){
        int u = st.top(); st.pop();
        cout << u << " ";
    }
    cout << "\n";


    /*for(int i = 1; i <= m; i++){
        cout << dp[i] << " \n"[i==m];
    }*/
    return 0;
}