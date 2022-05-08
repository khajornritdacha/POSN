#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e5+10;
int n,dp[N],a[N][2],qs[N][2],mx[2],mxed[2],mxst[2];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    mxed[0] = mxed[1] = 1e9;
    mxst[0] = mxst[0] = 1e9;
    cin >> n;
    for(int i=1; i<=n; i++){
        char code;
        int val;
        cin >> code >> val;
        if(code == 'R')
            a[i][0] = val;
        else
            a[i][1] = val;
        qs[i][0] = qs[i-1][0]+a[i][0];
        qs[i][1] = qs[i-1][1]+a[i][1];
    }

    if(DEBUG){
        for(int t=0; t<2; t++){
            for(int i=1; i<=n; i++){
                cout << qs[i][t] << " \n"[i==n];
            }
        }
    }

    for(int cur=0; cur<2; cur++){
        memset(dp, 0, sizeof(dp));
        int st,ed,sum=0;
        for(int i=1; i<=n; i++){
            int now = -a[i][cur]+a[i][!cur];
            if(now >= dp[i-1]+now){
                dp[i] = now;
                st = i;
                ed = i;
                sum = 0;
            }else{
                dp[i] = dp[i-1]+now;
                ed = i;
            }
            sum += a[i][!cur];

            now = qs[st-1][cur]+sum+qs[n][cur]-qs[ed][cur];
            if(now > mx[cur]){
                mx[cur] = now;
                mxst[cur] = st;
                mxed[cur] = ed;
            }else if(now == mx[cur]){
                if(ed-st+1 < mxed[cur]-mxst[cur]+1){
                    mxst[cur] = st;
                    mxed[cur] = ed;
                }
            }
        }

        if(DEBUG){
            for(int i=1; i<=n; i++){
                cout << dp[i] << " \n"[i==n];
            }
        }

    }

    if(mx[0] >= mx[1]){
        cout << "R " << mx[0] << " " << mxst[0] << " " << mxed[0];
    }else{
        cout << "L " << mx[1] << " " << mxst[1] << " " << mxed[1];
    }
}
