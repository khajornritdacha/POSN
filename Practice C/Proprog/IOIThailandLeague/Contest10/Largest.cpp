#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int R,C,a[N][N],s[N][N][5];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int mx = 0,row,col;
        cin >> R >> C;
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                cin >> a[i][j];
            }
        }
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(a[i][j] >= a[i][j-1])
                    s[i][j][3] = s[i][j-1][3]+1;
                else
                    s[i][j][3] = 1;
            }
        }
        for(int i=1; i<=R; i++){
            for(int j=C; j>=1; j--){
                if(a[i][j] >= a[i][j+1])
                    s[i][j][1] = s[i][j+1][1]+1;
                else
                    s[i][j][1] = 1;
            }
        }
        for(int j=1; j<=C; j++){
            for(int i=1; i<=R; i++){
                if(a[i][j] >= a[i-1][j])
                    s[i][j][0] = s[i-1][j][0]+1;
                else
                    s[i][j][0] = 1;
            }
        }
        for(int j=1; j<=C; j++){
            for(int i=R; i>=1; i--){
                if(a[i][j] >= a[i+1][j])
                    s[i][j][2] = s[i+1][j][2]+1;
                else
                    s[i][j][2] = 1;
            }
        }

        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(a[i][j] >= a[i-1][j] and a[i][j] >= a[i][j-1] and a[i][j] >= a[i+1][j] and a[i][j] >= a[i][j+1]){
                    int tmp = s[i-1][j][0]+s[i][j-1][3]+s[i+1][j][2]+s[i][j+1][1]+1;
                    if(tmp > mx){
                        mx = tmp;
                        row = i, col = j;
                    }
                }
            }
        }

        cout << mx << "\n" << row << " " << col << "\n";

        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                s[i][j][0] = s[i][j][1] = s[i][j][2] = s[i][j][3] = 0;
            }
        }
    }
}
