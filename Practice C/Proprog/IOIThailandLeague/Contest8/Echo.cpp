#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,cnt;
string str[N];

main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str[i];
    }
    for(int i=0; i<n; i++){
        string pat,tmp,tmp2;
        cin >> pat;
        int l=0, r=str[i].size()-1;
        for(; l<r; l++,r--){
            tmp.push_back(str[i][r]);
            tmp.push_back(str[i][l]);
        }
        if(str[i].size()%2)
            tmp.push_back(str[i][r]);
        tmp2 = tmp;
        reverse(tmp2.begin(), tmp2.end());
        tmp += tmp2;
        if(tmp.compare(pat) == 0){
            cnt++;
        }
    }
    cout << cnt << "\n";
}
