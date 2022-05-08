#include<bits/stdc++.h>
using namespace std;

const int N = 30;
using ll = long long;

int nw[N],ns[N];

int main(void){
    nw[0] = 1;
    for(int i = 1; i <= 24; i++){
        nw[i] = nw[i-1]+ns[i-1]+1;
        ns[i] = nw[i-1];
    }
    while(true){
        int year; cin >> year;
        if(year == -1) return 0;
        cout << nw[year] << " " << nw[year]+ns[year]+1 << "\n";
    }
    return 0;
}
