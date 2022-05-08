#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int cost[4] = {0, 104, 108, 116}, n, idx = 1;
char str[N];

int solve(){
    vector<int> vec;
    for(; idx <= n; idx++){
        if(str[idx] == ']'){
            break;
        } else if (str[idx] == '['){
            idx++;
            vec.emplace_back(solve());
        } else if (str[idx] >= 'A' and str[idx] <= 'Z') {
            vec.emplace_back(20);
        } else {
            vec.emplace_back(str[idx]-'0');
        }
    }

    for(int t = 3; t >= 1; t--){
        vector<int> nvec;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i] <= 3 and vec[i] == t){
                int tmp = nvec.back();
                nvec.pop_back();
                nvec.emplace_back((tmp+vec[i+1])*cost[t]/100);
                i++;
            } else {
                nvec.emplace_back(vec[i]);
            } 
        }
        vec = nvec;
    }

    return vec[0];
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> (str+1);
    n = strlen(str+1);

    cout << solve() << "\n";    

    return 0;
}