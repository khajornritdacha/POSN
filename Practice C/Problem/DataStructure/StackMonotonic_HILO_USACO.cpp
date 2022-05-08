//Source : USACO 2021 December contest (GOLD)
//http://www.usaco.org/index.php?page=viewproblem2&cpid=1162
//Sol : http://www.usaco.org/current/data/sol_prob2_gold_dec21.html
//Monotonic stack

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n, pos[N], arr[N], pre[N], res[N];

int main(void){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    stack<int> st;
    st.push(0);
    for(int v = n; v >= 1; v--){ //(val, pos) -> (4, 2), (2, 5) ...
        while(st.top() > pos[v]) st.pop();
        pre[pos[v]] = st.top();
        st.push(pos[v]);
    }
    while(st.size() > 1) st.pop();

    int ans = 0;
    cout << ans << "\n";
    for(int v = 1; v <= n; v++){
        while(st.top() > pos[v]){
            ans -= res[st.top()];
            st.pop();
        }

        res[pos[v]] = (pre[pos[v]] != 0 and (st.top() == 0 or pre[st.top()] != pre[pos[v]]));

        ans += res[pos[v]];
        st.push(pos[v]);
        cout << ans << "\n";
    }
    return 0;
}