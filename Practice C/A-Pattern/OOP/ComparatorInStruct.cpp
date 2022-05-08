#include<bits/stdc++.h>
using namespace std;
struct DATA{
    int val,i,j;
    bool operator < (const DATA &D)const{
        if(val == D.val){
            if(i == D.i)
                return j > D.j;
            return i > D.i;
        }
        return val > D.val;
    }
};
priority_queue<DATA> pq;
main(){
    pq.push({100,1,1});
    pq.push({100,2,1});
    pq.push({92,1,1});
    while(!pq.empty()){
        auto [x,y,z] = pq.top();
        pq.pop();
        cout << x << " " << y << " " << z << "\n";
    }
}
