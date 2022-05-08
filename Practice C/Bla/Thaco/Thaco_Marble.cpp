#include<bits/stdc++.h>
using namespace std;
int n,m;
main(){
    ios_base::sync_with_stdio(0);   cin.tie(0);
    cin >> n >> m;
    int a[n+5][m+5],dp[n+5][m+5],bt[n+5][m+5];
    pair<int,int> keep[n+5][m+5];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            char x;
            cin >> x;
            if(x=='R')
                a[i][j]=1;
            else
                a[i][j]=0;
            keep[i][j]={0,0};
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int x,y;
            if(a[i][j]==1) x=1,y=0;
            else x=0,y=1;
            int ru=keep[i-1][j].first+x,gu=keep[i-1][j].second+y;
            int rl=keep[i][j-1].first+x,gl=keep[i][j-1].second+y;
            int mu=min(ru,gu);
            int ml=min(rl,gl);
            if(mu>ml){
                dp[i][j]=mu;
                keep[i][j].first=keep[i-1][j].first+x;
                keep[i][j].second=keep[i-1][j].second+y;
                bt[i][j]=1;
            }else{
                dp[i][j]=ml;
                keep[i][j].first=keep[i][j-1].first+x;
                keep[i][j].second=keep[i][j-1].second+y;
                bt[i][j]=0;
            }
        }
    }
    stack<char> st;
    cout << dp[n][m]*2;
    int nr=n,nc=m;
    int gcnt=0,rcnt=0;
    while(nr>=1&&nc>=1){
        if(bt[nr][nc]==1){
            st.emplace('D');
            nr-=1;
        }else{
            st.emplace('R');
            nc-=1;
        }
        if(a[nr][nc]==1){
            if(rcnt<dp[n][m]){
                rcnt++;
                st.emplace('Y');
            }else{
                st.emplace('N');
            }
        }else{
            if(gcnt<dp[n][m]){
                gcnt++;
                st.emplace('Y');
            }else{
                st.emplace('N');
            }
        }

    }
    int cnt=0;
    cout << "\n";
    while(st.size()!=1){
        cout << st.top();
        if(++cnt==2){
            cout << "\n";
            cnt=0;
        }else{
            cout << " ";
        }
        st.pop();
    }
}
