#include<bits/stdc++.h>
using namespace std;

/*
Lang: C++
TASK: Brick
AUTHOR: Mahathep JomnoiZ
CENTER: SU Number 1
*/

const int N = 1010;

char last[N],ans[N],cur[N];
int L, n;
bool chk;

void cpy(char A[], char B[]){
    for(int l = 0; l < L; l++) A[l] = B[l];
}

int main(void){
    scanf(" %d %d", &R, &C);
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            scanf(" %c", &a[i][j]);
        }
    }

    for(int i = 1; i <= C; i++) scanf(" %d", &num[i]);

    for(int c = 1; c <= C; c++){
        int mx = R+1;
        for(int r = 1; r <= R; r++) if(a[r][c] == 'O'){ mx = r; break; }
        for(int r = mx-1; r >= 1 and num[i] > 0; r--){ a[r][c] = '#'; }
    }

    for(int r = 1; r <= R; r++){
        for(int c = 1; c <= C; c++){
            printf("%c", a[r][c]);
        }
        printf("\n");
    }
}
