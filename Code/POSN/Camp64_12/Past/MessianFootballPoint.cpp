#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
int n;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int win,dr,lo;
        win = dr = lo = 0;
        for(int j=1; j<=38; j++){
            char c;
            cin >> c;
            if(c == 'W')
                win++;
            else if(c == 'D')
                dr++;
            else
                lo++;
        }
        cout << win << " " << dr << " " << lo << " " << 2*win+dr << " " << 3*win+dr << " " << 5*win+dr-lo << "\n";
    }
}
