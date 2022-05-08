#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int n;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec.emplace_back(x);
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end())-vec.begin());
    for(int v : vec)
        cout << v << " ";
}
