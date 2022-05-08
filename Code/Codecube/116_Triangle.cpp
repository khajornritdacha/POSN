#include<bits/stdc++.h>
#define int long long
using namespace std;

int S;

void solve(){
    int last=-1,cnt=0;
    for(int a=1; a<S; a++){
        if(a == last) break;
        if((S*S-2*S*a)%(2*S-2*a) == 0){
            int b = (S*S-2*S*a)/(2*S-2*a);
            if(b < a)
                break;
            cnt++;
            last = b;
            cout << a << " " << b << " " << S-(a+b) << "\n";
        }
    }
    if(cnt == 0)
        cout << "-1\n";
}

main(void){
    int T,cnt=0;
    cin >> T;
    while(T--){
        cin >> S;
        cout << "Case #" << ++cnt << ":\n";
        solve();
    }
}

