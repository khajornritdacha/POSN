#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
main(){
    vector<pair<int,int>> vec;
    vec.emplace_back(1,3);
    vec.emplace_back(2,2);
    vec.emplace_back(2,1);
    sort(vec.begin(),vec.end(), [&](const pi a, const pi b){
         if(a.first!=b.first)
            return a.first>b.first;
         return a.second<b.second;
    });
    for(auto [x,y] : vec)
        cout << x << " " << y << "\n";
}
