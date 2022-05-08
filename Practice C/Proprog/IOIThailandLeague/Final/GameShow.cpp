#include<bits/stdc++.h>
using namespace std;

int R,C,n,r[15],c[15],mx;
vector<int> vec;

main(){
    cin >> R >> C >> n;
    for(int i=1; i<=n; i++){
        cin >> r[i] >> c[i];
        vec.emplace_back(i);
    }

    do{
        int sum = 0;
        for(int i=1; i<n; i++){
            sum += abs(r[vec[i]]-r[vec[i-1]])+abs(c[vec[i]]-c[vec[i-1]]);
        }
        mx = max(mx, sum);
    }while(next_permutation(vec.begin(), vec.end()));

    cout << mx << "\n";
}
