#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int a[1000005],N;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> a[i];
        int k = lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
        if(k==vec.size()){
            vec.emplace_back(a[i]);
        }else{
            vec[k] = a[i];
        }
    }
    cout << N-vec.size();
}
