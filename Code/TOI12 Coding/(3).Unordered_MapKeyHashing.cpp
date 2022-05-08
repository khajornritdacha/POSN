#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;

typedef pair<int,int> COOR;

template <class T> class pairHash;

template<>
class pairHash<COOR>{
public:
    size_t operator()(const COOR& A)const{
        return A.first + A.second;
    }
};
unordered_map<int, int> um;
unordered_map<COOR, COOR, pairHash<COOR> > map1;

int main(){
    um[1] = 10;
    um[-1] = -100;
    um[1000]++;
    um[1000000000]++;
    for(unordered_map<int, int>::iterator it = um.begin(); it != um.end(); it++){
        printf("%d %d\n", it->first, it->second);
    }
    map1[make_pair(1, 2)] = make_pair(3, 4);
    unordered_map<COOR, COOR, pairHash<COOR> >::iterator it = map1.find(make_pair(1, 2));
    printf("(%d, %d) (%d, %d)\n", it->first.first, it->first.second, it->second.first, it->second.second);
    if(map1.find(make_pair(3, 5)) != map1.end()){
        printf("Found (3, 5)\n");
    }
    else
        printf("Not Found (3, 5)\n");
    for(unordered_map<COOR, COOR, pairHash<COOR> >::iterator it = map1.begin(); it != map1.end(); it++){
        printf("(%d,%d) (%d,%d)\n", it->first.first, it->first.second, it->second.first, it->second.second);
    }
    return 0;
}
