#include<bits/stdc++.h>
using namespace std;
int n;
bool visit[1010][1010][110],dp[1010][1010][110];
string str,A,B;
bool solve(int i, int j, int s){
    if(i==0||j==0) return dp[i][j][n];
    if(visit[i][j][n]) return dp[i][j][n];
    visit[i][j][n]=true;
    if(A[i-1]==str[s-1]){
        dp[i][j][n]=max(dp[i][j][n],solve(i-1,j,s-1));
    }
    if(B[j-1]==str[s-1]){
        dp[i][j][n]=max(dp[i][j][n],solve(i,j-1,s-1));
    }
    return dp[i][j][n];
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> A >> B >> n;
   while(n--){
        cin >> str;
        for(int i=1; i<=A.size(); i++){
            if(A[i-1]==str[i-1]){
                dp[i][0][n]=1;
            }else{
                break;
            }
        }
        for(int j=1; j<=B.size(); j++){
            if(B[j-1]==str[j-1]){
                dp[0][j][n]=1;
            }else{
                break;
            }
        }
        cout << ((solve(A.size(),B.size(),A.size()+B.size())==1) ? "Yes" : "No") << "\n";
        /*for(int i=0; i<=A.size(); i++){
            for(int j=0; j<=B.size(); j++){
                 cout << dp[i][j][n] << " ";
            }
            cout << "\n";
        }
        //cout << dp[2][1];*/
   }
}

