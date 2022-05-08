#include<bits/stdc++.h>
using namespace std;
const int N = 5e4+10;
int n,cnt,ans,m;
char str[N][10],pat[25][10];
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> str[i];
    }
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> pat[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cnt = 0;
            for(int k=0; k<3; k++){
                if(str[i][3+k] == pat[j][k])
                    cnt++;
            }
            if(cnt == 3)
                ans++;
        }
    }
    cout << ans;
}
