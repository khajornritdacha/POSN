#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
string str;
bool ok = true;
int cnt[15];
set<int> ss;
main(){
    for(int i=0; i<7; i++)
        ss.insert(i);
    while(ok){
        cin >> str;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '!'){
                ok = false;
                break;
            }
            if(isalpha(str[i])){
                cnt[str[i]-'A']++;
            }
        }
        if(!ok) break;
        if(ss.size() == 1) continue;
        int mn = 1e9,nub=0,kud;
        for(int s : ss){
            mn = min(mn,cnt[s]);
        }
        for(int s : ss){
            if(mn == cnt[s]){
                nub++;
                kud = s;
            }
        }
        if(nub == 1){
            ss.erase(kud);
        }
    }
    vector<pair<int,int>> vec;
    for(int s : ss){
        vec.emplace_back(cnt[s], s);
    }
    sort(vec.begin(), vec.end(), [&](const pi &a, const pi &b){
        if(a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    });
    cout << vec.size() << "\n";
    for(int i=0; i<vec.size(); i++){
        int x,y;
        tie(x,y) = vec[i];
        cout << char(y+'A') << " " << x << "\n";
    }
}
