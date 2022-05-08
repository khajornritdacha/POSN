#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+10;
char a[N][N];
bool ver[N][N],hor[N][N];
int R,C;

void go(int sr, int sc, int pr, int pc){
    int sz = 1;
    while(pr*sz+sr >= 1 and pr*sz+sr <= R and pc*sz+sc >= 1 and pc*sz+sc <= C and a[pr*sz+sr][pc*sz+sc] == '.'){
        if(pc == 0)
            ver[pr*sz+sr][pc*sz+sc] = true;
        else
            hor[pr*sz+sr][pc*sz+sc] = true;
        sz++;
    }
}
main(){
    cin >> C >> R;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(a[i][j] == 'V'){
                go(i, j, 1, 0);
            }else if(a[i][j] == '>'){
                go(i, j, 0, 1);
            }else if(a[i][j] == '<'){
                go(i, j, 0, -1);
            }else if(a[i][j] == '^'){
                go(i, j, -1, 0);
            }
        }
    }

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(a[i][j] == 'B'){
                a[i][j] = '*';
            }else if(a[i][j] == '.'){
                if(ver[i][j] and hor[i][j])
                    a[i][j] = '+';
                else if(ver[i][j])
                    a[i][j] = '|';
                else if(hor[i][j])
                    a[i][j] = '-';
            }
        }
    }

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
}
