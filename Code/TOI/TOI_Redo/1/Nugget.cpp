#include<bits/stdc++.h>
using namespace std;

/*
Lang: C++
TASK: Nugget
AUTHOR: Mahathep JomnoiZ
CENTER: SU Numberr 1
*/

int main(void){
    int n; scanf(" %d", &n);
    
    bool chk[n+5] = {};
    chk[0] = 1;
    for(int nug : {6, 9, 20}){
        for(int i = nug; i <= n; i++){
            chk[i] |= chk[i-nug];
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += chk[i];
        if(chk[i]) cout << i << "\n";
    }
    if(!cnt) cout << "no\n";
}