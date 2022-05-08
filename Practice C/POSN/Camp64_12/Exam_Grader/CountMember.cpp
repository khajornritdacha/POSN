#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int S,n,sz[N],a[N][N];

main(){
    cin >> S >> n;
    for(int i=0; i<S; i++){
        while(sz[i] < n){
            int x;
            cin >> x;
            if(x <= 0)
                break;
            a[i][sz[i]++] = x;
        }
    }
    for(int i=0; i<S; i++){
        for(int j=0; j<S; j++){
            if(i == j) continue;
            int cnt = 0;
            for(int k=0; k<sz[i]; k++){
                for(int l=0; l<sz[j]; l++){
                    if(a[i][k] == a[j][l])
                        cnt++;
                }
            }
            cout << cnt << " ";
        }
        cout << "\n";
    }
}
