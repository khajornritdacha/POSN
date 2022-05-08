#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int n,mx,pos,ans;
main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        vec.emplace_back(x);
    }
    for(; ;){
        mx = 0;
        for(int i=1; i<vec.size(); i++){
            if(abs(vec[i]-vec[i-1]) > mx){
                mx = abs(vec[i]-vec[i-1]);
                pos = i;
            }
        }
        ans += mx;
        vec.erase(vec.begin()+pos-1, vec.begin()+pos+1);
        if(vec.size() <= 1)
            break;
    }
    cout << ans;
}
