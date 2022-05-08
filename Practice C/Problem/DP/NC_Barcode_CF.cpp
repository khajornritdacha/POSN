#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
long long R,C,X,Y,qs[1010][2],dp[1010][2];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> X >> Y;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            char x;
            cin >> x;
            if(x=='#')
                qs[j][1]++;
            if(i==R)
                qs[j][0]=R-qs[j][1];
        }
    }
    for(int j=1; j<=C; j++){
        qs[j][1]+=qs[j-1][1];
        qs[j][0]+=qs[j-1][0];
        if(DEBUG){
            cout << qs[j][0] << " " << qs[j][1] << "\n";
        }
    }
    for(int j=1; j<=C; j++){
        for(int c=0; c<=1; c++){
            dp[j][c]=2e9;
            for(int k=X; k<=Y; k++){
                if(j-k<0) break;
                dp[j][c]=min(dp[j][c],dp[j-k][!c]+qs[j][!c]-qs[j-k][!c]);
            }
            if(DEBUG){
                cout << dp[j][c] << " ";
            }
        }
        if(DEBUG){
            cout << "\n";
        }
    }
    cout << min(dp[C][0],dp[C][1]) << "\n";
}

/*
https://codeforces.com/contest/225/problem/C
*/
