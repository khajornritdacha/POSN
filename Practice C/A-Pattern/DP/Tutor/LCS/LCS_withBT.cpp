#include<bits/stdc++.h>
using namespace std;
string s,t;
int dp[105][105];
main(){
    cin >> t >> s;
    for(int i=1; i<=t.size(); i++) for(int j=1; j<=s.size(); j++) dp[i][j] = -1;
    for(int i=1; i<=t.size(); i++){
        for(int j=1; j<=s.size(); j++){
            if(t[i-1]==s[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    for(int i=0; i<=t.size(); i++){
        for(int j=0; j<=s.size(); j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "LCS: " << dp[t.size()][s.size()] << "\n";
    int i=t.size(), j=s.size();
    stack<char> st;
    while(i>0 && j>0){
        if(t[i-1] == s[j-1]){
            st.push(t[i-1]);
            i--;
            j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}
