#include<bits/stdc++.h>
using namespace std;
int po(int p){
    int tmp = 2, ret = 1;
    for(; p; p/=2, tmp*=tmp){
        if(p%2)
            ret = ret*tmp;
    }
    //cout << tmp << "\n";
    return ret;
}
main(){
    int n;
    cin >> n;
    cout << po(n);
}
