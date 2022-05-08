#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
char a[N][100];
int n,S[50],H[50],last,mx;
void us(int x, int y, int c){
    char te='/';
    if(c)
        te = '\\';
    if(a[x][y] == '.')
        a[x][y] = te;
    else if(a[x][y] != 'X' and a[x][y] != te){
        a[x][y] = 'v';
    }
}
void tr(int x, int y){
    a[x][y] = 'X';
}
main(){
    cin >> n;
    for(int i=0; i<=10000; i++) for(int j=0; j<=100; j++) a[j][i] = '.';
    for(int i=1; i<=n; i++){
        cin >> S[i] >> H[i];
        mx = max(mx, H[i]);
    }
    for(int i=1; i<=n; i++){
        int s = S[i];
        int h = mx-H[i]+1;
        for(int x=0; x<H[i]; x++){
            for(int y=0; y<H[i]; y++){
                if(x+y == H[i]-1)
                    us(h+x, s+y, 0);// cout << h+x << " " << s+y << "\n";
                else if(x+y >= H[i])
                    tr(h+x, s+y);
                last = max(last, s+y);
            }
        }
        s = S[i]+H[i];
        for(int x=0; x<H[i]; x++){
            for(int y=0; y<H[i]; y++){
                if(x==y)
                    us(h+x, s+y, 1);
                else if(y<x)
                    tr(h+x, s+y);
                last = max(last, s+y);
            }
        }
    }
    for(int i=1; i<=mx; i++){
        for(int j=1; j<=last; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
}
