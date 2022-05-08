#include<bits/stdc++.h>
using namespace std;


int a[1010],n,M;

void pr(){
    for(int i=1; i<=n; i++){
        cout << a[i] << " \n"[i==n];
    }
}
main(){
    cin >> n >> M;
    pr();
    for(int i=1; i<=M*2; i++){
        int x,ch;
        cin >> x;
        if(i%2)
            ch = 1;
        else
            ch = 2;
        a[x] = ch;
        pr();
    }
}
