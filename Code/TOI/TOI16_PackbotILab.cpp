#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
string str;
int n,L[N],R[N],dp[N][N];
bool use[N];
void solve(int l, int r, int cd){
    stack<int> par;
    for(int i=l; i<=r; i++){
        if(str[i] == '[')
            par.push(i);
        else if(str[i] == ']')
            par.pop();
        if(!par.empty())
            continue;
        if(str[i] == cd+'0' and !use[i]){
            use[i] = true;
            int le = L[i-1];
            int ri = R[i+1];
            R[le] = ri;
            L[ri] = le;
            int sum = dp[le][i-1]+dp[i+1][ri];
            if(cd == 3)
                sum = sum+sum*0.16;
            else if(cd == 2)
                sum = sum+sum*0.08;
            else if(cd == 1)
                sum = sum+sum*0.04;
            dp[le][ri] = sum;
        }
    }
}
main(){
    cin >> str;
    n = str.size();
    for(int i=0; i<n; i++){
        L[i] = R[i] = i;
        dp[i][i] = 20;
    }
    //cout << dp[0][n-1] << "\n";
    stack<int> par;
    for(int i=0; i<n; i++){
        if(str[i] == '[')
            par.push(i);
        else if(str[i] == ']'){
            int tp = par.top();
            par.pop();
            solve(tp+1, i-1, 3);
            solve(tp+1, i-1, 2);
            solve(tp+1, i-1, 1);
            R[tp] = i;
            L[i] = tp;
            dp[tp][i] = dp[tp+1][i-1];
        }
    }
    solve(0, n-1, 3);
    solve(0, n-1, 2);
    solve(0, n-1, 1);
    cout << dp[0][n-1];
}
