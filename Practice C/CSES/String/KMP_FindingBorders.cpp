#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10, INF = 1e9;

string str;
int pi[N];

int main(void){
    cin >> str;
    for(int i = 1; i < str.size(); i++){
        int j = pi[i-1];
        while(j > 0 and str[i] != str[j])
            j = pi[j-1];
        if(str[i] == str[j])
            j++;
        pi[i] = j;
    }

    /*for(int i = 0; i < str.size(); i++){
        cout << pi[i] << " ";
    }
    cout << "\n";*/

    int now = pi[(int)str.size()-1];
    vector<int> ans;
    while(now > 0){
        ans.emplace_back(now);
        now = pi[now-1];
    }
    reverse(ans.begin(), ans.end());
    for(int an : ans) cout << an << " ";
    return 0;
}
