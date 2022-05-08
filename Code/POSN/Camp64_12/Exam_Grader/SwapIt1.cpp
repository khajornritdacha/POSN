#include<bits/stdc++.h>
using namespace std;

int a[10][10];
main(){
    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            cin >> a[i][j];
        }
    }
    int M;
    cin >> M;
    for(int i=1; i<=M; i++){
        int c,r,code;
        cin >> c >> r >> code;
        if(code == 0 and c-1 > 0)
            swap(a[r][c], a[r][c-1]);
        else if(code == 1 and r-1 > 0)
            swap(a[r][c], a[r-1][c]);
        else if(code == 2 and c+1 <= 8)
            swap(a[r][c], a[r][c+1]);
        else if(code == 3 and r+1 <= 8)
            swap(a[r][c], a[r+1][c]);

        int po = 0,sh=0,sv=0;
        while(true){
            if(a[r+po][c] != a[r][c])
                break;
            po++;
        }
        sh += po;
        po=0;
        while(true){
            if(a[r-po][c] != a[r][c])
                break;
            po++;
        }
        sh += po-1;
        po=0;
        while(true){
            if(a[r][c+po] != a[r][c])
                break;
            po++;
        }
        sv += po;
        po=0;
        while(true){
            if(a[r][c-po] != a[r][c])
                break;
            po++;
        }
        sv += po-1;

        cout << "H " << sv << " V " << sh << "\n";
    }

}
