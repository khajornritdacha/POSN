#include<bits/stdc++.h>
using namespace std;
int pr[]={-1,-1,0,1,1,1,0,-1},pc[]={0,1,1,1,0,-1,-1,-1},n,lr,lc;
char pat[]={'O', 'X'},a[15][15];
bool chk(bool cur, int r, int c, int lv){
    if(a[r+pr[lv]][c+pc[lv]] != pat[cur] and a[r+pr[lv]][c+pc[lv]] != '.'){
        //cout << "now : " << cur << " " << r << " " << c << " " << lv << "\n";
        char la = '.';
        for(int i=pr[lv],j=pc[lv]; a[i+r][j+c] != '.'; i+=pr[lv],j+=pc[lv]){
            if(a[i+r][j+c] == pat[cur]){
                lr = i+r, lc = j+c;
                return true;
            }
        }
    }
    return false;
}
void cha(bool cur, int r, int c, int lv){
    a[r][c] = pat[cur];
    for(int i=pr[lv],j=pc[lv]; i+r!=lr or j+c!=lc; i+=pr[lv],j+=pc[lv]){
        a[r+i][c+j] = pat[cur];
    }
}
main(){
    for(int i=0; i<=10; i++) for(int j=0; j<=10; j++) a[i][j] = '.';
    a[4][5] = a[5][4] = 'X';
    a[4][4] = a[5][5] = 'O';
    cin >> n;
    bool cur = true;
    for(int i=1; i<=n; i++){
        char cc;
        int r,c;
        cin >> cc >> r;
        c = cc-'a'+1;
        bool ok = false;
        //cout << "Cur : " << cur << "\n";
        for(int k=0; k<2; k++){
            for(int j=0; j<8; j++){
                if(chk(cur, r, c, j)){
                    ok = true;
                    cha(cur, r, c, j);
                }
            }
            cur = !cur;
            if(ok)
                break;
        }
    }
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
}
