#include <bits/stdc++.h>
using namespace std;

int a[25][25],R=20,C=20;

int main(void){
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(i >= 4){
                ans = max(ans, a[i][j]*a[i-1][j]*a[i-2][j]*a[i-3][j]);
            }
            if(i <= 17){
                ans = max(ans, a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j]);
            }
            if(j >= 4){
                ans = max(ans, a[i][j]*a[i][j-1]*a[i][j-2]*a[i][j-3]);
            }
            if(j <= 17){
                ans = max(ans, a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3]);
            }
            if(i >= 4 and j >= 4){
                ans = max(ans, a[i][j]*a[i-1][j-1]*a[i-2][j-2]*a[i-3][j-3]);
            }
            if(i >= 4 and j <= 17){
                ans = max(ans, a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3]);
            }
        }
    }
    cout << ans;
    return 0;
}
