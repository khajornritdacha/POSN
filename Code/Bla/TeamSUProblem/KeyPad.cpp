#include<bits/stdc++.h>
using namespace std;
string str;
vector<int> pos[30];
int dp[1000100],ans=2e9;
int solve(int i){
    if(str[i]=='A')
        return i;
    if(dp[i]!=0)
        return dp[i];
    int pp=str[i]-'A'-1;
    //cout << "I: " << i << " " << pp << "\n";
    int mn=2e9;
    int k= upper_bound(pos[pp].begin(),pos[pp].end(),i)-pos[pp].begin();
    //cout << "K: " << k << "\n";
    if(k!=pos[pp].size()){
        mn=min(mn,solve(pos[pp][k])+abs(i-pos[pp][k]));
    }
    if(k!=0){
        k--;
        //cout << "PP: " << pos[pp][k] << "\n";
        mn=min(mn,solve(pos[pp][k])+abs(i-pos[pp][k]));
    }
    return dp[i]=mn;
}
main(){
    cin >> str;
    for(int i=0; i<str.size(); i++){
        pos[str[i]-'A'].emplace_back(i);
    }
    for(int i=0; i<pos['Z'-'A'].size(); i++){
        ans=min(ans,solve(pos['Z'-'A'][i]));
    }
    cout << ans << '\n';
}
