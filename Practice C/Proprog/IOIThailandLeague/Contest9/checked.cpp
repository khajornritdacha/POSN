#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
const int N = 1e6+10;
int n,num[2],now[2],cnt[2],ta[N][2],pat[2][2];
long long ans;
///There are only four pattern: B-B, B-W, W-B, W-W
main(){
    cin >> n >> num[0] >> num[1];
    for(int bit=0; bit<4; bit++){
        for(int j=0; j<=n; j++) ta[j][0] = ta[j][1] = 0;
        for(int t=0; t<2; t++){
            now[t] = ((bit&(1<<t)) != 0);
            int col = 0;
            for(int j=now[t]*num[t]+1; j<=n; j++){
                ta[j][t] = 1;
                if(++col == num[t]){
                    col = 0, j+=num[t];
                }
            }
        }
        if(DEBUG){
            cout << now[0] << " " << now[1] << "\n";
            cout << "a : ";
            for(int i=1; i<=n; i++)
                cout << ta[i][0] << " \n"[i==n];
            cout << "b : ";
            for(int i=1; i<=n; i++)
                cout << ta[i][1] << " \n"[i==n];
            cout << "u : ";
            for(int i=1; i<=n; i++)
                cout << (ta[i][1] | ta[i][0]) << " \n"[i==n];
            cout << "\n";
        }
        for(int j=1; j<=n; j++)
            pat[now[0]][now[1]] += (ta[j][0]|ta[j][1]);
    }
    now[0]=now[1]=0;
    for(int i=1; i<=n; i++){
        ans += pat[now[0]][now[1]];
        for(int j=0; j<2; j++){
            if(++cnt[j] == num[j]){
                cnt[j] = 0, now[j]=!now[j];
            }
        }
    }
    cout << ans << "\n";
}
///https://www.proprog.ml/tasks/checked/descs/7301
