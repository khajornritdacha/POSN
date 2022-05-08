#include<bits/stdc++.h>
using namespace std;
int n,mx;
vector<int> vec;
deque<int> dq;
main(){
    cin >> n;
    vec.resize(n);
    for(int &v : vec)
        cin >> v;
    sort(vec.begin(), vec.end());
    for(int v : vec){
        if(dq.size()>2){
            while(dq.size() >=2 && dq[0]+dq[1]<=v)
                dq.pop_front();
            mx = max(mx, (int)dq.size());
        }
        dq.push_back(v);
    }
    cout << mx+1 << "\n";
}
