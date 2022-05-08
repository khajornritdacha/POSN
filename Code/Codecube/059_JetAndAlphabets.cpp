#include<bits/stdc++.h>
using namespace std;


main(){
    int cnt = 0,R,C;
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cout << (char)(cnt+'A');
            cnt++;
            cnt%=26;
        }
        cout << "\n";
    }
}
