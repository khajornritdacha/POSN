#include<bits/stdc++.h>
using namespace std;

/*
Lang: C++
TASK: Chain
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
    scanf(" %d %d", &L, &n);
    scanf(" %s", last);
    for(int i = 2; i <= n; i++){
        scanf(" %s", cur);
        int cnt = 0;
        //printf("%s\n%s\n\n", last, cur);
        for(int l = 0; l < L; l++){
            if(cur[l] != last[l]) cnt++;
        }
        if(!chk and cnt > 2){
            chk = true;
            cpy(ans, last);
        }
        cpy(last, cur);
    }
    if(!chk) cpy(ans, last);
    printf("%s\n", ans);
}
