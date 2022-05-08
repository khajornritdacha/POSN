#include <bits/stdc++.h>
using namespace std;

int L,M,n;

int main(void){
    cin >> L >> M >> n;
    for(int i = 1; i <= n; i++){
        bool ok = true; int pos = 0;
        for(int j = 1; j <= M; j++){
            int x; cin >> x;
            if(x == 0){
                pos--;
            }else{
                pos++;
            }
            if(abs(pos) > L){
                ok = false;
            }
        }
        cout << ok << "\n";
    }
    return 0;
}
