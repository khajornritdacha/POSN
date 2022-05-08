#include <bits/stdc++.h>
using namespace std;

void solve(){
    int R, C;
    cin >> R >> C;

    char arr[30][30] = {};
    for(int r = 0; r <= 2*R+1; r++) for(int c = 0; c <= 2*C+1; c++) arr[r][c] = '.';

    for(int r = 1; r <= 2*R+1; r++){
        if(r%2){
            for(int c = 1; c <= 2*C+1; c++){
                if(c%2){
                    arr[r][c] = '+';
                } else {
                    arr[r][c] = '-';
                }
            }
        } else {
            for(int c = 1; c <= 2*C+1; c += 2){
                arr[r][c] = '|';
            }
        }
    }
    arr[1][1] = arr[1][2] = arr[2][1] = arr[2][2] = '.';
    
    for(int r = 1; r <= 2*R+1; r++){
        for(int c = 1; c <= 2*C+1; c++){
            cout << arr[r][c];
        }
        cout << "\n";
    }

    return;
}

int main(void){
    int test_case; cin >> test_case;
    for(int t = 1; t <= test_case; t++){
        cout << "Case #" << t << ":\n";
        solve();
    }

    return 0;
}