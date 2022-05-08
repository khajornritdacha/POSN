#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
char c[20],ans[10][N];
int mx;
main(){
    cin >> c+1;
    int n = strlen(c+1);
    for(int i=1; i<=100; i++) for(int j=1; j<=5; j++) ans[j][i] = '.';
    for(int i=1,j=3; i<=n; i++,j+=4){
        if(i%3 == 0) continue;
        ans[1][j] = '#';
        ans[2][j-1] = '#';
        ans[2][j+1] = '#';
        ans[3][j-2] = '#';
        ans[3][j] = c[i];
        ans[3][j+2] = '#';
        ans[4][j-1] = '#';
        ans[4][j+1] = '#';
        ans[5][j] = '#';
        mx = max(mx, j+2);
    }
    for(int i=1,j=3; i<=n; i++,j+=4){
        if(i%3 != 0) continue;
        ans[1][j] = '*';
        ans[2][j-1] = '*';
        ans[2][j+1] = '*';
        ans[3][j-2] = '*';
        ans[3][j] = c[i];
        ans[3][j+2] = '*';
        ans[4][j-1] = '*';
        ans[4][j+1] = '*';
        ans[5][j] = '*';
        mx = max(mx, j+2);
    }
    for(int i=1; i<=5; i++){
        for(int j=1; j<=mx; j++){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
