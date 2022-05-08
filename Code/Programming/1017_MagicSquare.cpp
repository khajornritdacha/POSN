#include<bits/stdc++.h>
using namespace std;
const int N = 15;
set<int> s;
int n,a[N][N],row[N],col[N],di,rdi;
bool ok = true;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            s.insert(a[i][j]);
            row[i]+=a[i][j];
            col[j]+=a[i][j];
            if(i == j)
                di+=a[i][j];
            if(i+j-1 == n)
                rdi+=a[i][j];
        }
    }
    int ans = di;
    for(int i=1; i<=n; i++){
        if(ans!=row[i] or ans!=col[i])
            ok = false;
    }
    if(ok and s.size()==n*n and di == rdi)
        cout << "Yes\n";
    else
        cout << "No\n";
}
