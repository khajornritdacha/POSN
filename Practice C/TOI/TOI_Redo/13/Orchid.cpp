#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int n,a[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    vector<int> vec;
    for(int i = 1; i <= n; i++){
        int k = upper_bound(vec.begin(), vec.end(), a[i])-vec.begin();
        if(k == vec.size()) vec.emplace_back(a[i]);
        else vec[k] = a[i];
    }
    cout << n-(int)vec.size() << "\n";
}