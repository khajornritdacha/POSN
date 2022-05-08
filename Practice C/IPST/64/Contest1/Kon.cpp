#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10, INF = 1e9;

int dp[N], bt[N], ct[N];

int main(void){
    for(int i = 2; i < N; i++) dp[i] = INF;
    for(int i = 1; i < N; i++){
        for(int j = i+i, cnt = 1; j < N; j += i, cnt++){
            int tmp = dp[i] + 3 + cnt;
            if(tmp < dp[j]){
                dp[j] = tmp;
                bt[j] = i;
                ct[j] = cnt;
            }
        }
    }

    freopen("1.out", "w", stdout);
    cout << 10 << "\n";
    for(int t = 1; t <= 10; t++){
        cout << t << "\n";
        int k; cin >> k;
        stack<char> st;
        while(k != 1){
            for(int i = 0; i < ct[k]; i++){
                st.push('V');
            }
            st.push('V');
            st.push('C');
            st.push('A');
            k = bt[k];
        }
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
        cout << "\n";
    }
    return 0;
}