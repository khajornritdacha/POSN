#include<bits/stdc++.h>
using namespace std;

int n,m,K,L,C,sum;


main(){
    cin >> n >> m >> K >> L  >> C;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int x;
            cin >> x;
            sum += x;
        }
    }
    sum += K*L*C;
    cout << (sum+C-1)/C;
}
