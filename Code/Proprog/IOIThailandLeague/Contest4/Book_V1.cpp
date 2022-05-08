#include<bits/stdc++.h>
using namespace std;
const int N = 3e4+10;
string str[N];
int fen[N],n,idx[N];
vector<pair<string,int>> vec;
void up(int i, int val){
    while(i <= n){
        fen[i] += val;
        i += i&-i;
    }
}
int qs(int i){
    int res = 0;
    while(i){
        res += fen[i];
        i -= i&-i;
    }
    return res;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> str[i];
        for(int j=0; j<str[i].size(); j++){
            if(str[i][j] >= 'a' and str[i][j] <= 'z')
                str[i][j]-='a'-'A';
        }
        vec.emplace_back(str[i], i);
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i<vec.size(); i++){
        idx[vec[i].second] = i+1;
    }
    for(int i=1; i<=n; i++){
        up(idx[i], 1);
        cout << qs(idx[i]) << "\n";
    }
}
