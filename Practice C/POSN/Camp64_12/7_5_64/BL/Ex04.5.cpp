#include<bits/stdc++.h>
using namespace std;

vector<long long> ans;
long long pw[30];

void gen(int l, int r, long long now = 0){
    if(l > r){
        ans.emplace_back(now);
        return;
    }
    for(int i=0; i<=9; i++){
        if(l==0 and i==0) continue;
        if(l == r)
            gen(l+1, r-1, now+pw[l]*i);
        else
            gen(l+1, r-1, now+pw[l]*i+pw[r]*i);
    }
}
main(){
    ans.emplace_back(0);
    pw[0] = 1;
    for(int i=1; i<=12; i++)
        pw[i] = pw[i-1]*10;
    for(int i=0; i<12; i++){
        gen(0, i);
    }

    cout << ans.size() << "\n";
    for(long long an : ans){
        cout << an << "\n";
    }
}
