#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int pw[14];
void gen(int la, int mx, int lv = 0, int now = 0){
    if(lv == mx){
        vec.emplace_back(now);
        return;
    }
    for(int i=la+1; i<=9; i++){
        gen(i, mx, lv+1, now+i*pw[mx-lv-1]);
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    pw[0] = 1;
    for(int i=1; i<=9; i++){
        pw[i] = pw[i-1]*10;
    }
    for(int i=1; i<=9; i++){
        gen(0, i);
    }
    int Q;
    cin >> Q;
    while(Q--){
        long long x;
        cin >> x;
        if(x > vec.size())
            cout << "-1";
        else
            cout << vec[x-1];
        cout << "\n";
    }
}
