#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6+10;
using pi = pair<int,int>;

int n,a[N];

///https://www.spoj.com/problems/DOSA/

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> lis;

    for(int i = 1; i <= n; i++){
        if(a[i] < i) continue;
        int k = upper_bound(lis.begin(), lis.end(), a[i]-i)-lis.begin();
        //cout << i << " " << k << " " << lis[k] << "\n";
        assert(k >= 0);
        if(k == lis.size()){
            lis.emplace_back(a[i]-i);
        }else{
            lis[k] = a[i]-i;
        }
    }

    /*for(int val : lis){
        cout << val << "\n";
    }*/

    cout << n-(int)lis.size() << "\n";
    return 0;
}
