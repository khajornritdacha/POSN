#include<bits/stdc++.h>
using namespace std;
int R,C,M,pr[]={-1,1,0,0},pc[]={0,0,-1,1},res;
char a[30][30];
int chk(int r, int c){
    char tmp = a[r][c];
    int cou = 0;
    a[r][c] = '-';
    for(int i=0; i<4; i++){
        if(a[r+pr[i]][c+pc[i]] == tmp)
            cou+=chk(r+pr[i], c+pc[i]);
    }
    return cou+5;
}
void down(){
    for(int i=R; i>=1; i--){
        for(int j=1; j<=C; j++){
            if(a[i][j] == '-' or a[i][j] == '#') continue;
            int tmp = i;
            while(a[tmp+1][j] == '-'){
                a[tmp+1][j] = a[tmp][j];
                a[tmp++][j] = '-';
            }
        }
    }
}
void mov(int r, int c, char code){
    int go;
    down();
    if(code == 'L')
        go=-1;
    else
        go=1;
    if(r<1 or r>R or c<1 or c>C or c+go>C or c+go<1 or a[r][c+go]!='-' or !isalpha(a[r][c])){ res-=5; return;}
    int last = r;
    for(int i=r; i<=R; i++){
        if(a[i][c+go] == '-')
            last = i;
        else
            break;
    }
    swap(a[r][c], a[last][c+go]);
}
bool eli(){
    bool con = false;
    int tmp = 0;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            bool ok = false;
            for(int k=0; k<4; k++){
                if(a[i][j]!= '#' and a[i][j] != '-' and a[i+pr[k]][j+pc[k]] == a[i][j])
                    ok=true;
            }
            if(ok){
                con = true;
                res+=chk(i, j);
            }
        }
    }
    return con;
}
main(){
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> a[i][j];
        }
    }
    cin >> M;
    for(int i=1; i<=M; i++){
        int r,c;
        char code;
        cin >> r >> c >> code;
        mov(++r, ++c, code);
        while(eli())
            down();
    }
    cout << res << "\n";
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
