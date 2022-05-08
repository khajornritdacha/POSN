#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1005][1005],zero[1005],ans,cnt;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j]==0)
                zero[i]++;
        }
    }
    int o=0,keb=0,ma;
    queue<int> qq;
    for(int i=n;i>=1;i--){
        keb += zero[i+1];
        cnt=0,ma=0;
        o = keb;
        for(int j=1;j<=m;j++){
            if(a[i][j]==0){
                cnt++;
                ma = max(ma,cnt);
            }
            else{
                int k=1;
                while(1){
                    if(j-k>=0&&a[i][j-k]==0){
                        k++;
                    }else
                        break;
                }
                qq.emplace(k);
                if(o>0){
                    cnt++;
                    o--;
                    ma = max(ma,cnt);
                }else{
                    if(qq.empty())
                        cnt=0;
                    else{
                        cnt-=qq.front();
                        cnt++;
                        qq.pop();
                    }
                }
            }
            if(ma>=k){
                cout << i;
                return 0;
            }
        }
    }
}
