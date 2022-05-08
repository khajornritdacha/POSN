#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using ll = long long;



int main(void){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    string str; cin >> str;
    vector<int> cnt(26);
    int cou = 0;
    for(int i = 0; i <str.size(); i++){
        cnt[str[i]-'A']++;
    }
    for(int i = 0; i < 26; i++){
        cou += cnt[i]%2;
    }
    if(str.size()%2 == 0 and cou or str.size()%2 and cou > 1){ cout << "NO SOLUTION\n"; return 0;}
    int n = str.size();
    vector<char> res(n+1);
    for(int i = 1; i <= n/2; i++){
        for(int j = 0; j < 26; j++){
            if(cnt[j] >= 2){
                cnt[j] -= 2;
                res[i] = res[n-i+1] = 'A'+j;
                break;
            }
        }
    }
    if(n%2){
        for(int j = 0; j < 26; j++){
            if(cnt[j]){
                cnt[j]--;
                res[(n+1)/2] = 'A'+j;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << res[i];
    }
    return 0;
}
