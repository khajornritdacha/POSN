#include <bits/stdc++.h>
using namespace std;

const int N = 35;

int n,B,a[N][N],ans;

int main(void){
    cin >> n >> B;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){///Current
        for(int j = 1; j <= n; j++){

            for(int k = 1; k <= n; k++){///Compare
                for(int l = 1; l <= n; l++){
                    if(i != k){
                        ans = max(ans, 2*B + abs(a[i][j]-a[k][l]) );
                    }
                    ans = max(ans, abs(a[i][j]-a[k][l]));
                }
            }

        }
    }
    cout << ans << "\n";
    return 0;
}
