#include<bits/stdc++.h>
using namespace std;

const int N = 2510;
using ll = long long;

int now[10],Q;
char str[N];

void cal(char X){
    int tmp[10] = {};
    if(X == 'F'){
        tmp[1] = now[4];
        tmp[2] = now[1];
        tmp[3] = now[3];
        tmp[4] = now[6];
        tmp[5] = now[5];
        tmp[6] = now[2];
    }else if(X == 'B'){
        tmp[1] = now[2];
        tmp[2] = now[6];
        tmp[3] = now[3];
        tmp[4] = now[1];
        tmp[5] = now[5];
        tmp[6] = now[4];
    }else if(X == 'L'){
        tmp[1] = now[5];
        tmp[2] = now[2];
        tmp[3] = now[1];
        tmp[4] = now[4];
        tmp[5] = now[6];
        tmp[6] = now[3];
    }else if(X == 'R'){
        tmp[1] = now[3];
        tmp[2] = now[2];
        tmp[3] = now[6];
        tmp[4] = now[4];
        tmp[5] = now[1];
        tmp[6] = now[5];
    }else if(X == 'C'){
        tmp[1] = now[1];
        tmp[2] = now[5];
        tmp[3] = now[2];
        tmp[4] = now[3];
        tmp[5] = now[4];
        tmp[6] = now[6];
    }else{
        tmp[1] = now[1];
        tmp[2] = now[3];
        tmp[3] = now[4];
        tmp[4] = now[5];
        tmp[5] = now[2];
        tmp[6] = now[6];
    }

    for(int i = 1; i <= 6; i++) now[i] = tmp[i];
}

int main(void){
    cin >> Q;
    while(Q--){
        cin >> str;
        now[1] = 1;
        now[2] = 2;
        now[3] = 3;
        now[4] = 5;
        now[5] = 4;
        now[6] = 6;
        for(int i = 0; str[i] != '\0'; i++){
            cal(str[i]);
        }
        cout << now[2] << "  ";
    }
    return 0;
}
