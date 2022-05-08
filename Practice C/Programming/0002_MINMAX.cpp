#include<bits/stdc++.h>
using namespace std;
int n;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int minn = 2e9,maxx = -2e9;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        minn = min(minn,temp);
        maxx = max(maxx,temp);
    }
    cout << minn << "\n" << maxx;
}
