#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int mn = 1e9,dp[N][10];
char str[N];

main(){
    cin >> str+1;
    int n = strlen(str+1);
    for(int i=0; i<=n; i++){
        for(int j=0; j<=8; j++){
            dp[i][j] = 1e9;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=8; j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
        }
        if(str[i] == 'c'){
            dp[i][1] = min(dp[i][1], 1);
            dp[i][5] = min(dp[i][5], dp[i-1][4]+1);
        }else if(str[i] == 'o'){
            dp[i][2] = min(dp[i][2], dp[i-1][1]+1);
        }else if(str[i] == 'd'){
            dp[i][3] = min(dp[i][3], dp[i-1][2]+1);
        }else if(str[i] == 'e'){
            dp[i][4] = min(dp[i][4], dp[i-1][3]+1);
            dp[i][8] = min(dp[i][8], dp[i-1][7]+1);
        }else if(str[i] == 'u'){
            dp[i][6] = min(dp[i][6], dp[i-1][5]+1);
        }else if(str[i] == 'b'){
            dp[i][7] = min(dp[i][7], dp[i-1][6]+1);
        }
    }
    int st;
    for(int i=1; i<=n; i++){
        if(dp[i][8] < mn){
            mn = dp[i][8];
            st = i;
        }
    }
    if(mn == 1e9){
        cout << "-1\n";
    }else{
        cout << st-mn+1 << " " << st << "\n";
    }
}
