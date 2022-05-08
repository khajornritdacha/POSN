#include<bits/stdc++.h>
using namespace std;

using pi = pair<int,int>;

pi operator+(const pi &A, const pi &B){
    return pi(A.first+B.first, A.second+B.second);
}

pi operator-(const pi &A, const pi &B){
    return pi(A.first-B.first, A.second-B.second);
}

main(){
    pi a = {5, 3};
    pi b = {1, 7};
    pi res = a-b;
    cout << res.first << " " << res.second << "\n";
}
