#include<bits/stdc++.h>
using namespace std;
char ipt;
int C,R,sq,tri,rh;
bitset<2005> a[10005];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> C >> R;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> ipt;
            a[i][j] = ipt-'0';
        }
    }
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(a[i-1][j-1] == 0 and a[i-1][j] == 0 and a[i-1][j+1] == 0 and a[i][j-1] == 0 and a[i][j] == 1 and a[i][j+1] == 1 and a[i+1][j-1] == 0 and a[i+1][j] == 1 and a[i+1][j+1] == 1){
                ///sq
                sq++;
            }else if(a[i-1][j-1] == 0 and a[i-1][j] == 0 and a[i-1][j+1] == 0 and a[i][j-1] == 0 and a[i][j] == 1 and a[i][j+1] == 0 and a[i+1][j-1] == 1 and a[i+1][j] == 1 and a[i+1][j+1] == 0){
                ///left tri
                tri++;
            }else if(a[i-1][j-1] == 0 and a[i-1][j] == 0 and a[i-1][j+1] == 0 and a[i][j-1] == 0 and a[i][j] == 1 and a[i][j+1] == 0 and a[i+1][j-1] == 0 and a[i+1][j] == 1 and a[i+1][j+1] == 1){
                ///ri tri
                tri++;
            }else if(a[i-1][j-1] == 0 and a[i-1][j] == 0 and a[i-1][j+1] == 0 and a[i][j-1] == 0 and a[i][j] == 1 and a[i][j+1] == 1 and a[i+1][j-1] == 0 and a[i+1][j] == 0 and a[i+1][j+1] == 1){
                ///upside down tri
                tri++;
                int k=1;
                for(; ; k++){
                    if(a[i+k][j+k] == 0)
                        break;
                }
                a[i+k-1][j+k-1] = 0;
            }
        }
    }
    for(int i=R; i>=1; i--){
        for(int j=C; j>=1; j--){
            if(a[i-1][j-1] == 1 and a[i-1][j] == 0 and a[i-1][j+1] == 0 and a[i][j-1] == 1 and a[i][j] == 1 and a[i][j+1] == 0 and a[i+1][j-1] == 0 and a[i+1][j] == 0 and a[i+1][j+1] == 0){
                ///up tri
                tri++;
            }else if(a[i-1][j-1] == 1 and a[i-1][j] == 1 and a[i-1][j+1] == 1 and a[i][j-1] == 0 and a[i][j] == 1 and a[i][j+1] == 0 and a[i+1][j-1] == 0 and a[i+1][j] == 0 and a[i+1][j+1] == 0){
                ///rhombus
                rh++;
            }
        }
    }
    /*cout << "\n";
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }*/
    cout << sq << " " << rh << " " << tri;
}
