#include <bits/stdc++.h>
using namespace std;

int solve(int R, int C, char **board){
    int res = 0;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            if(board[i][j] == '#') res++;
            cout << board[i][j];
        }
        cout << "\n";
    }

    return res;
}

int main(void){
    int R, C; cin >> R >> C;
    char **board = new char*[R+5];
    for(int i = 1; i <= R; i++){
        board[i] = new char[C+5];
        for(int j = 1; j <= C; j++){
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <= R; i++){ for(int j = 1; j <= C; j++){ cout << board[i][j]; } cout << "\n"; } cout << "\n";

    int res = solve(R, C, board);
    cout << res << "\n";

    return 0;
}