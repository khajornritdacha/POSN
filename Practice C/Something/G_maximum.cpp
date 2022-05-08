#include<bits/stdc++.h>
using namespace std;
multiset < pair<int,int > > s;
main(){
    s.insert({5,3});
    s.insert({4,2});
    s.insert({5,1});
    auto it  = s.upper_bound({4,2}).first;
    cout << *it.first;
}
