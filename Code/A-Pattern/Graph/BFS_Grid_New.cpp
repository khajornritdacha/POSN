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

void bfs(int r, int c){
    queue< pair<int, int> > qq;
    qq.push({r, c});
    vi[r][c] = true;
    while(!qq.empty()){
        // Get current position
        auto [r, c] = qq.front(); qq.pop();

        // Propate to the adjacent blocks
        for(int i = 0; i < 4; i++){
            int nr = r+dr[i], nc = c+dc[i];
            if(in_border(nr, nc) and !vi[nr][nc]){
                qq.push({nr, nc});
                vi[nr][nc] = true;
            }
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
            if(!vi[r][c]){
                bfs(r, c);
            }
        }
    }

}