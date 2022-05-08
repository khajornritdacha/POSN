#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
bool zero;
long long now,mi,mul=1;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        char code;
        int val;
        cin >> code >> val;
        if(code == 'x'){
            if(val == 0)
                zero = true;
            else
                mul *= val;
        }else if(code == '+'){
            now += val;
        }else{
            mi += val;
        }
    }
    now *= mul;
    if(zero)
        mi = 0;
    now -= mi;
    cout << now << "\n";
}
