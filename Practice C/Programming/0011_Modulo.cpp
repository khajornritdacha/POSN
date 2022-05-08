#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+10;
set<int> s;
main(){
    for(int i=0; i<10; i++){
        int x;
        cin >> x;
        s.insert(x%42);
    }
    cout << s.size();
}
