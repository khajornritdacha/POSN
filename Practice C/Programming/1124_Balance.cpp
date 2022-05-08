#include<bits/stdc++.h>
using namespace std;
long long n,pw[25];
vector<pair<long long,int>> vec;
void gen(){
    for(int i=0; i<(1<<20); i++){
        int now = 0;
        long long sum = 0;
        for(int j=0; j<20; j++){
            if(i&(1<<j)){
                now|=(1<<j);
                sum+=pw[j];
            }
        }
        vec.emplace_back(sum, now);
        if(sum == n){
            cout << __builtin_popcount(now) << " " << sum << "\n";
            exit(0);
        }
    }
}
main(){
    pw[0] = 1;
    for(int i=1; i<20; i++)
        pw[i] = pw[i-1]*3;
    cin >> n;
    gen();
    sort(vec.begin(), vec.end());
    for(auto &[key, val] : vec){
        //cout << key << " " << val << "\n";
        int k1=lower_bound(vec.begin(), vec.end(), make_pair(key-n, 0))-vec.begin();
        if(vec[k1].first == key-n){
            int val2 = vec[k1].second;
            //cout << "Found : " << key-n << " " << mp[key-n] << " " << (int)(val&val2) << "\n";
            if((val&val2) == 0){
                cout << __builtin_popcount(val)+__builtin_popcount(val2) << " " << key << "\n";
                return 0;
            }
        }
    }
}
