#include<bits/stdc++.h>
using namespace std;

vector<long long> ans;
long long pw[30];

void gen(int r, int l, long long now=0){
    if(r < l){
        ans.emplace_back(now);
        return;
    }
    for(int i=0; i<=9; i++){
        if(i == 0 and l == 0) continue;
        if(l == r)
            gen(r-1, l+1, now+pw[r]*i);
        else
            gen(r-1, l+1, now+pw[r]*i+pw[l]*i);
    }
}
main(){
    ans.emplace_back(0);
    pw[0] = 1;
    for(int i=1; i<=12; i++){
        pw[i] = pw[i-1]*10;
    }

    ///Gen Odd digit Palindrome
    for(int i=1; i<=12; i++){
        gen(i-1, 0);
    }

    ///Gen Even digit Palindrome
    for(int i=1; i<=1e6-1; i++){
        long long now = i;
        int tmp = i;
        while(tmp){
            now*=10;
            now+=tmp%10;
            tmp/=10;
        }
        //cout << now;
        ans.emplace_back(now);
        //cout << "\n";
    }
    sort(ans.begin(), ans.end());
    cout << "Total : " << ans.size() << "\n";
    for(int an : ans)
        cout << an << "\n";
}
