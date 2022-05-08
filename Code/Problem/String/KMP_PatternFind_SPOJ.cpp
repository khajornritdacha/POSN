#include <bits/stdc++.h>
using namespace std;

///https://www.spoj.com/problems/NAJPF/

void test_case(){
    string str,tx;
    cin >> str >> tx;
    vector<int> ans, pi(tx.size()+5);
    for(int i = 1, idx = 0; i < tx.size(); i++){
        while(idx > 0 and tx[idx] != tx[i]){
            idx = pi[idx-1];
        }
        if(tx[idx] == tx[i])
            idx++;
        pi[i] = idx;
    }

    for(int i = 0, idx = 0; i < str.size(); i++){
        while(idx > 0 and str[i] != tx[idx]){
            idx = pi[idx-1];
        }
        if(str[i] == tx[idx])
            idx++;
        if(idx == tx.size()){
            ans.push_back(i-tx.size()+2);
        }
    }

    if(ans.size() == 0){
        cout << "Not Found\n";
    }else{
        cout << ans.size() << "\n";
        for(int an : ans) cout << an << " ";
        cout << "\n";
    }

    cout << "\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
