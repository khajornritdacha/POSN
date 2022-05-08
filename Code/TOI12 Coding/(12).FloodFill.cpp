#include <cstdio>
#include <queue>
using namespace std;
// Flood Fill in 4-Direction

class NODE{
public:
    int r, c;
    NODE(int r, int c){
        this->r = r;
        this->c = c;
    }
};

int R, C;
int diR[] = {-1, 0, 0, 1};
int diC[] = {0, -1, 1, 0};
char Grid[1005][1005];

void Fill(int stR, int stC){
    queue<NODE> q;
    q.push(NODE(stR, stC));
    Grid[stR][stC] = '#';
    while(!q.empty()){
        int r = q.front().r, c = q.front().c;
        q.pop();
        for(int i = 0; i < 4; ++i){
            int nR = r+diR[i], nC = c+diC[i];
            if(nR >= 1 && nR <= R && nC >= 1 && nC <= C && Grid[nR][nC] == '.'){
                Grid[nR][nC] = '#';
                q.push(NODE(nR, nC));
            }
        }
    }
}

int main(){
    int cntLand = 0;
    scanf("%d%d", &R, &C);
    for(int i = 1; i <= R; ++i){
        scanf("%s", &Grid[i][1]);
    }
    for(int i = 1; i <= R; ++i){
        for(int j = 1; j <= C; ++j){
            if(Grid[i][j] == '.'){
                Fill(i, j);
                cntLand++;
            }
        }
    }
    printf("This Grid has %d Land(s).", cntLand);
    return 0;
}
/*
5 5
...#.
...#.
####.
.#.#.
.#.#.

5 5
.....
.....
####.
.....
.....

5 5
.....
....#
#####
.....
.....
*/
