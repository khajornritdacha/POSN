#include<bits/stdc++.h>
using namespace std;

int pat[10][3][3] = {   {{0,1,0},{1,0,1},{1,1,1}},
                        {{0,0,0},{0,0,1},{0,0,1}},
                        {{0,1,0},{0,1,1},{1,1,0}},
                        {{0,1,0},{0,1,1},{0,1,1}},
                        {{0,0,0},{1,1,1},{0,0,1}},
                        {{0,1,0},{1,1,0},{0,1,1}},
                        {{0,1,0},{1,1,0},{1,1,1}},
                        {{0,1,0},{0,0,1},{0,0,1}},
                        {{0,1,0},{1,1,1},{1,1,1}},
                        {{0,1,0},{1,1,1},{0,1,1}},
                    };
int num[10][10],hr,mn;
bool a[3][15];
string str[3];

int chk(int sc, int lim, int code){
    int cnt=0;
    for(int k=0; k<=lim; k++){
        bool ok = true;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(a[i][sc+j] == 1 and pat[k][i][j] == 0){
                    ok = false;
                }
            }
        }
        if(ok){
            cnt++;
            num[code][k]++;
            //cout << sc << " " << k << "\n";
        }
    }
    return cnt;
}

main(){
    int ans = 1;
    for(int i=0; i<3; i++){
        getline(cin, str[i]);
        //cout << str[i] << "\n";
        for(int j=0; j<str[i].size(); j++){
            if(str[i][j] != ' '){
               a[i][j] = 1;
            }
        }
    }
    /*for(int i=0; i<3; i++){
        for(int j=0; j<13; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }*/

    chk(0, 9, 0);
    chk(3, 9, 1);
    chk(7, 9, 2);
    chk(10, 9, 3);
    for(int i=0; i<=2; i++){
        for(int j=0; j<=(i==2 ? 3 : 9); j++){
            hr += num[0][i]*num[1][j];
        }
    }
    for(int i=0; i<=5; i++){
        for(int j=0; j<=9; j++){
            mn += num[2][i]*num[3][j];
        }
    }

    cout << hr*mn;
}
