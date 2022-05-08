#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,a[N][N],m,mnr[N],mnc[N],mxr[N],mxc[N],cnt;
main(){
    cin >> n >> m;
    for(int i=1; i<=max(m,n); i++)
        mnr[i] = mnc[i] = 1e9;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
            mnr[i] = min(mnr[i], a[i][j]);
            mnc[j] = min(mnc[j], a[i][j]);
            mxr[i] = max(mxr[i], a[i][j]);
            mxc[j] = max(mxc[j], a[i][j]);
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] >= mxr[i] and a[i][j] <= mnc[j] or a[i][j] >= mxc[j] and a[i][j] <= mnr[i]){
                cout << "("<<i-1<<", "<<j-1<<") = "<<a[i][j] << "\n";
                cnt++;
            }
        }
    }
    if(!cnt)
        cout << "None";
}
