#include<bits/stdc++.h>
using namespace std;
class knap{
public:
    int wei;
    int val;
    knap(int wei,int val){
        this->wei = wei;
        this->val = val;
    }
};
vector<knap> vec;
int N,W,dp[10005];
main(){
    cin >> W >> N;
    for(int i=0;i<N;i++){
        int wei,val;
        cin >> wei >> val;
        vec.emplace_back(knap(wei,val));
    }
    for(int i=0;i<N;i++){
        for(int j=W;j>=vec[i].wei;j--){
            dp[j] = max(dp[j],dp[j-vec[i].wei]+vec[i].val);
        }
    }
    cout << dp[W];
}
