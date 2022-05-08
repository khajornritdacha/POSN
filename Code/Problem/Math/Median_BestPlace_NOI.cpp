#include <bits/stdc++.h>
using namespace std;

//https://oj.uz/problem/view/NOI17_bestplace

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int x[n+10], y[n+10];
    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    
    sort(x+1, x+n+1);
    sort(y+1, y+n+1);

    int med = (n+1)/2;

    cout << x[med] << " " << y[med] << "\n";

    return 0;   
}