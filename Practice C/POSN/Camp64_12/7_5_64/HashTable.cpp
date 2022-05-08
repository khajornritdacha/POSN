#include<bits/stdc++.h>
using namespace std;

int a[110];

void ins(int x){
    int i = x%10, cnt = 0;
    while(true){
        if(cnt > 10)
            return;
        if(a[i] == 0){
            a[i] = x;
            return;
        }
        i++;
        cnt++;
        if(i == 10)
            i = 0;
    }
}
int sea(int val){
    int i = val%10, cnt = 0;
    while(true){
        if(a[i] == 0)
            return -1;
        if(cnt > 10)
            return -1;
        if(a[i] == val)
            return i;
        i++; cnt++;
        if(i == 10)
            i = 0;
    }
}
void del(int val){
    int i = val%10, cnt = 0;
    while(true){
        if(a[i] == val){
            a[i] = -1e9;
            return;
        }
        if(cnt > 10)
            return;
        i++, cnt++;
        if(i == 10)
            i = 0;
    }
}
main(){
    ins(10010);
    ins(1210);
    ins(914120);

    int pos = sea(1210);
    cout << pos << "\n";

    pos = sea(30010);
    cout << pos << "\n";

    ins(30);
    pos = sea(30);
    cout << pos << "\n";

    del(30);
    pos = sea(30);
    cout << pos << "\n";

    for(int i=0; i<10; i++){
        cout << a[i] << " \n"[i==9];
    }
}
