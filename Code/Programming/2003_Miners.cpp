#include<bits/stdc++.h>
using namespace std;
int n,a[100010],dp[4][4][4][4][4];
string str;
int cal(int x, int b, int c){
    int cnt=0;
    for(int i=1; i<=3; i++)
        if(x==i || b==i || c==i)
            cnt++;
    return cnt;
}
main(){
    cin >> n;
    cin >> str;
    for(int i=0; i<n; i++){
        if(str[i] == 'M')
            a[i] = 1;
        else if(str[i] == 'B')
            a[i] = 2;
        else if(str[i] == 'F')
            a[i] = 3;
    }
    for(int t=n-1; t>=0; t--){
        int now = t%2;
        int nex = (t+1)%2;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                for(int k=0; k<4; k++){
                    for(int l=0; l<4; l++){
                        dp[now][i][j][k][l] = max(cal(a[t],i,j) + dp[nex][a[t]][i][k][l], cal(a[t],k,l) + dp[nex][i][j][a[t]][k]);
                    }
                }
            }
        }
    }
    cout << dp[0][0][0][0][0];
}
