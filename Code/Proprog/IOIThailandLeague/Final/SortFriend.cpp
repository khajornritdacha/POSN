#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,string>> vec;
string str;
int n,a[30],cnt[30];


main(){
    cin >> str >> n;
    for(int i=0; i<str.size(); i++){
        a[str[i]-'A']++;
    }
    for(int i=1; i<=n; i++){
        int sum = 0;
        cin >> str;
        for(int i=0; i<str.size(); i++){
            cnt[str[i]-'A']++;
        }
        for(int i=0; i<26; i++){
            sum += a[i]*cnt[i];
            cnt[i] = 0;
        }
        vec.emplace_back(sum, -i, str);
    }
    sort(vec.rbegin(), vec.rend());
    for(int i=0; i<vec.size(); i++){
        cout << get<2>(vec[i]) << "\n";
    }
}
