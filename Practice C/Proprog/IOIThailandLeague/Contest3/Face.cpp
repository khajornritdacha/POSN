#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int R,C,ans;
char ta[N][N];
main(){
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> ta[i][j];
        }
    }
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(ta[i][j] == 'S' and ta[i+1][j] == 'N')
                ans++;
            if(ta[i][j] == 'E' and ta[i][j+1] == 'W')
                ans++;
        }
    }
    cout << ans;
}
