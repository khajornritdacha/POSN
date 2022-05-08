#include<bits/stdc++.h>
using namespace std;
multiset< pair<int,int> , greater<pair<int,int>> > s;
main()
{
    s.insert({2,1});
    s.insert({2,1});
    s.insert({2,1});
    s.insert({2,1});
    s.insert({2,1});
    auto tt = s.lower_bound({6,0});
    cout << tt->first << " " << tt->second << "\n";
    //cout << tt->first;
    s.erase(s.find({tt->first,tt->second}));
    /*for(auto it:s){
        cout << it.first << " " << it.second << "\n";
    }*/
}
/*
9
-7 10 11 9 2 3 8 8 1
*/
