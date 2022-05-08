#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> vec;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i=1;i<=N;i++){
        int temp;
        cin >> temp;
        int k = lower_bound(vec.begin(),vec.end(),temp)-vec.begin();
        if(k==vec.size()){
            vec.emplace_back(temp);
        }else{
            vec[k] = temp;
        }
    }
    cout << vec.size();
}
