#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int R,C,a[N][N],ans,cnt[15];

int main(void){
    cin >> R >> C;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 5; i <= R; i++){
        for(int j = 5; j <= C; j++){
            int cou = 0;
            for(int i1 = 0; i1 <= 4; i1++){
                for(int j1 = 0; j1 <= 4; j1++){
                    if(++cnt[a[i-i1][j-j1]] == 1) cou++;
                }
            }
            for(int i1 = 0; i1 <= 4; i1++){
                for(int j1 = 0; j1 <= 4; j1++){
                    --cnt[a[i-i1][j-j1]];
                }
            }
            if(cou >= 5) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
