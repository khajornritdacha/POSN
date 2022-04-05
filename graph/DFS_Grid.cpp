#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int R, C;
bool vi[N][N];

// 4 cases: up, left, right, down respectively
int dr[] = {-1, 0, 0, 1}; //difference in row 
int dc[] = {0, -1, 1, 0}; //difference in column 

bool in_border(int r, int c){
    return (1 <= r and r <= R and 1 <= c and c <= C);
}

void dfs(int r, int c){
    if(vi[r][c]) return;
    vi[r][c] = true;
    for(int i = 0; i < 4; i++){
        int nr = r+dr[i], nc = c+dc[i];
        if(in_border(nr, nc)){ //Check if it is out of border
            dfs(nr, nc);
        }
    }
}

int main(void){
    cin >> R >> C;
    // Input array
    // for(int r = 1; r <= R; r++){
    //     for(int c = 1; c <= C; c++){
    //         cin >> arr[r][c];
    //     }
    // }

    for(int r = 1; r <= R; r++){
        for(int c = 1; c <= C; c++){
            dfs(r, c);
        }
    }

}