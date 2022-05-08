#include<bits/stdc++.h>
using namespace std;

string str;
int n;

void dfs(int lv=0, int op=0, int ed=0){
    //cout << lv << " " << op << " " << ed <<  " " << str << "\n";
    if(lv == 2*n){
        cout << str << "\n";
        return;
    }
    if(op > ed and ed+1 <= n){
        str.push_back(')');
        dfs(lv+1, op, ed+1);
        str.pop_back();
    }
    if(op+1 <= n){
        str.push_back('(');
        dfs(lv+1, op+1, ed);
        str.pop_back();
    }
}

main(){
    cin >> n;
    dfs();
}
