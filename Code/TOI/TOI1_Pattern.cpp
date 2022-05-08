#include<bits/stdc++.h>
using namespace std;
int n,a[50055][100],maxx;
main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int r,st,du;
        cin >> r >> st >> du;
        maxx = max(r,maxx);
        for(int j=0;j<du;j++){
            a[r][st+j] = 1;
        }
    }
    for(int i=1;i<=maxx;i++){
        for(int j=1;j<=70;j++){
            if(a[i][j]==1)
                cout << "x";
            else
                cout << "o";
        }
        cout << "\n";
    }
}
