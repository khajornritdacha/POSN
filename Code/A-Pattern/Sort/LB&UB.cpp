#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;

main(){
    cin >> n;
    vec.resize(n);
    for(int &v : vec)
        cin >> v;

    sort(vec.begin(), vec.end());
    for(int v : vec)
        cout << v << " ";
    cout << "\n";

    int T;
    cin >> T;
    while(T--){
        int x;
        cin >> x;
        int k1 = lower_bound(vec.begin(), vec.end(), x)-vec.begin();
        int k2 = upper_bound(vec.begin(), vec.end(), x)-vec.begin();
        cout << "Lower : " << k1 << " " << vec[k1] << "\n"; ///First element that equal or greater than x
        if(k1 > 0)
            cout << "Biggest element that less than " << x << " is " << vec[k1-1] << "\n";
        cout << "Upper : " << k2 << " " << vec[k2] << "\n"; ///First element that strictly greater than x
        if(k2 > 0)
            cout << "Biggest element that equal or less than " << x << " is " << vec[k2-1] << "\n";
    }
}
