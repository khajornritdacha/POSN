#include<bits/stdc++.h>
using namespace std;

string str;

bool solve(int l, int r){
    if(l > r)
        return true;
    if(str[l] == str[r]){
        return solve(l+1, r-1);
    }
    return false;
}
main(){
    cin >> str;
    if(solve(0, (int)str.size()-1)){
        cout << "true";
    }else{
        cout << "false";
    }
}
