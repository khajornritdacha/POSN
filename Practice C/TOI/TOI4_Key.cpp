#include<bits/stdc++.h>
using namespace std;
int n,m;
string LX,LY,L;
vector<char> ans;
main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    cin >> LX >> LY;
    cin >> L;
    for(int i=0;i<m;i++){
        char now = L[i];
        for(int j=0;j<n;j++){
            vector<char> temp;
            temp.emplace_back(now);
            temp.emplace_back(LX[j]);
            temp.emplace_back(LY[j]);
            sort(temp.begin(),temp.end());
            now = temp[1];
        }
        ans.emplace_back(now);
    }
    for(auto x:ans)
        cout << x;
}
