#include<bits/stdc++.h>
using namespace std;

using pi = pair<int,int>;

template <class T> class pairHash;
template<>
class pairHash<pi>{
public:
    size_t operator()(const pi &A)const{
        return A.first+A.second;
    }
};
unordered_map<pi, int, pairHash<pi>> mp;

main(){
    mp[pi(1,5)] = 1;
    cout << mp[pi(1,5)];
}
