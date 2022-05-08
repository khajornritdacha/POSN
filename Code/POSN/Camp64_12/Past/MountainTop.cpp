#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,a[N][N];
vector<tuple<int,int,int>> ans;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    for(int i=2; i<n; i++){
        for(int j=2; j<n; j++){
            if(a[i][j] > a[i-1][j-1] and a[i][j] > a[i-1][j] and a[i][j] > a[i-1][j+1] and a[i][j] > a[i][j-1] and a[i][j] > a[i][j+1] and a[i][j] > a[i+1][j-1] and a[i][j] > a[i+1][j] and a[i][j] > a[i+1][j+1]){
                ans.emplace_back(a[i][j], i, j);
            }
        }
    }
    cout << ans.size() << "\n";
    //sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        int x,y,z;
        tie(x,y,z) = ans[i];
        cout << x << " " << y-1 << " " << z-1 << "\n";
    }
}
