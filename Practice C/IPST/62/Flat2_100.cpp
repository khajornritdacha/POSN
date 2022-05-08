#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n, W, a[N], L[N], R[N];

int main(void){
    cin >> n >> W;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    stack<int> st;
    st.push(0);
    a[0] = a[n+1] = -1;
    for(int i = 1; i <= n; i++){
        while(!st.empty() and a[st.top()] >= a[i]) st.pop();
        L[i] = st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();
    st.push(n+1);
    for(int i = n; i >= 1; i--){
        while(!st.empty() and a[st.top()] >= a[i]) st.pop();
        R[i] = st.top();
        st.push(i);
    }


    if(W == -10){
        vector<int> ans(n+5, -1);
        for(int i = 1; i <= n; i++){
            int tmp = R[i] - L[i] - 2;
            assert(tmp >= 0);
            if(a[i] > ans[tmp]){
                ans[tmp] = a[i];
            }
        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << "\n";
        
    } else {
        int ans = -1;
        for(int i = 1; i <= n; i++){
            if(R[i] - L[i] - 2 == W){
                ans = max(ans, a[i]);
            }
        }
        cout << ans << "\n";
    }
    

    return 0;
}