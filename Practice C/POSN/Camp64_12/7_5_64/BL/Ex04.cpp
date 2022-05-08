#include<bits/stdc++.h>
using namespace std;

vector<pair<int,string>> ans;
string tong[10];

main(){
    for(int i=0; i<=9; i++){
        for(int j=0; j<3; j++){
            tong[i].push_back(i+'0');
        }
        if(i != 0)
            ans.emplace_back(3, tong[i]);
    }
    for(char i='0'; i<='9'; i++){
        for(int j=0; j<=9; j++){
            if(i != '0' and j != 0){
                ans.emplace_back(4, i+tong[j]);
                ans.emplace_back(4, tong[j]+i);
            }
        }
    }
    for(char i='1'; i<='9'; i++){
        for(char k='0'; k<='9'; k++){
            for(int j=0; j<=9; j++){
                string tmp;
                tmp.push_back(i);
                tmp.push_back(k);
                ans.emplace_back(5, tmp+tong[j]);
                ans.emplace_back(5, i+tong[j]+k);
            }
        }
    }
    for(char i='0'; i<='9'; i++){
        for(char k='0'; k<='9'; k++){
            for(int j=1; j<=9; j++){
                ans.emplace_back(5, tong[j]+i+k);
            }
        }
    }
    //cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end())-ans.begin());
    cout << "Total " << ans.size() << "\n";
    for(auto x : ans)
        cout << x.second << "\n";
}
