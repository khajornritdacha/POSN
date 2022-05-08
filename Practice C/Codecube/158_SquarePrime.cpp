#include<bits/stdc++.h>
using namespace std;

vector<int> vec;
bitset<1010> chk;

main(){
    vec.emplace_back(4);
    for(int i=3; i<=1e3; i+=2){
        if(!chk[i]){
            vec.emplace_back(i*i);
            for(int j=i; j<=1e3; j+=i){
                chk[j] = true;
            }
        }
    }
    int a,b,cnt=0;
    cin >> a >> b;
    for(int i=0; i<vec.size(); i++){
        if(vec[i] >= a and vec[i] <= b){
            cout << vec[i] << " ";
            cnt++;
        }
    }
    if(cnt == 0)
        cout << "-1";
}
