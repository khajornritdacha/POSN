#include<bits/stdc++.h>
using namespace std;

int C,m,n,cnt;
char la = '.';

main(){
    cin >> C >> m >> n;
    for(int i=1; i<=n; i++){
        char x;
        cin >> x;
        if(x != la){
            cnt++;
        }
        la = x;
    }
    cout << (cnt+m-1)/m*C;
}
