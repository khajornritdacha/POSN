#include<bits/stdc++.h>
using namespace std;
const int N = 2e4+10;
struct ST{
    char name[35];
    int sc;
};
ST pa[10];
int n,mn=1e9;
main(){
    for(int i=1; i<=8; i++){
        ST tmp;
        cin >> tmp.name;
        tmp.sc = 0;
        pa[i] = tmp;
    }
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        pa[x].sc++;
    }
    for(int i=1; i<=8; i++){
        mn = min(mn, pa[i].sc);
    }
    for(int i=1; i<=8; i++){
        if(pa[i].sc != mn){
            cout << pa[i].name << "\n";
        }
    }
}
