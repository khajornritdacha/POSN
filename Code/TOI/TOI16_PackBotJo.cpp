#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

string str;
int idx;

int solve(){
    vector<int> vec[4];
    for(; idx < str.size(); idx++){
        if(str[idx] == '['){
            idx++;
            vec[3].emplace_back(solve());
        }else if(str[idx] == ']'){
            break;
        }else{
            if(isalpha(str[idx]))
                vec[3].emplace_back(20);
            else
                vec[3].emplace_back(str[idx]-'0');
        }
    }

    if(DEBUG){
        for(int v : vec[3]){
            cout << v << " ";
        }
        cout << "\n";
    }

    for(int k = 3; k >= 1; k--){
        for(int i = 0; i < vec[k].size(); i++){
            int now = vec[k][i];
            int res = vec[k][i];
            if(now == k){
                int val1 = vec[k-1].back();
                vec[k-1].pop_back();
                int val2 = vec[k][i+1];
                i++;

                res = val1+val2;
                if(k == 3)
                    res = (res*116)/100;
                else if(k == 2)
                    res = (res*108)/100;
                else
                    res = (res*104)/100;
            }
            vec[k-1].emplace_back(res);
        }
    }

    return vec[0].front();
}

main(){
    cin >> str;
    cout << solve();
}
