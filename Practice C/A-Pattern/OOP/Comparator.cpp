#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int>;
vector<pi> vec;
///sort in ascending for .first and descending for .second
bool cmp(const pi &A, const pi & B){
    if(A.first != B.first)
        return A.first < B.first;
    return A.second > B.second;
}
main(){
    vec.push_back({100,1});
    vec.push_back({100,2});
    vec.push_back({92,1});
    sort(vec.begin(), vec.end(), cmp);
    for(auto [x,y] : vec)
        cout << x << " " << y << "\n";
}
