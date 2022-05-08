#include<bits/stdc++.h>
using namespace std;

template<typename T1>
T1 maxx(const T1 &x, const T1 &y){
    if(x < y)
        return y;
    return x;
}
main(){
  cout << maxx(3, 4);
}
