#include<bits/stdc++.h>
using namespace std;
int n,k,r[110][110],l[110][110],sum;
vector<int> ans;
main(){
    cin >> n >> k;
    for(int i=0; i<=n; i++){
        for(int j=0; j<n; j++){
            cin >> r[i][j];
        }
        if(i==n) continue;
        for(int j=0; j<=n; j++){
            cin >> l[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int temp;
            temp=(r[i-1][j-1]-r[i][j-1])*3;
            temp+=(l[i-1][j-1]-l[i-1][j])*5;
            ans.emplace_back(temp);
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<k; i++){
        sum+=ans[i];
    }
    cout << sum;
}
