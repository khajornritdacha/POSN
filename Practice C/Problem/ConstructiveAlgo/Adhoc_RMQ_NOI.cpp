#include <bits/stdc++.h>
using namespace std;


//https://oj.uz/problem/view/NOI17_rmq

//let UR(i) be the union of all range for value i
//then UR(i) must contains value that is greater or equal to i
//let UI(i) be the intersection of all range for value i
//then UI(i) must contains i and filled other blank space with any values that is greater than i
//we can greedily fill each index of answer in an decreasing order of value

const int N = 1e5+10;

int n, Q, Li[N], Lu[N], Ri[N], Ru[N], ans[N];
set<int> rem_pos, rem_val;

void ex(){
    for(int i = 0; i < n; i++) cout << "-1 ";
    exit(0);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 0; i < n; i++){
        Li[i] = Ru[i] = -1e9;
        Lu[i] = Ri[i] = 1e9;        
        rem_pos.insert(i);
        rem_val.insert(i);
    }

    for(int i = 0; i < Q; i++){
        int l, r, x; cin >> l >> r >> x;
        Li[x] = max(Li[x], l), Ri[x] = min(Ri[x], r);
        Lu[x] = min(Lu[x], l), Ru[x] = max(Ru[x], r);
    }    

    for(int i = n-1; i >= 0; i--){
        if(Li[i] == -1e9) continue;
        if(Li[i] > Ri[i]) ex();
        
        auto itp = rem_pos.lower_bound(Li[i]);
        if(itp == rem_pos.end() or *itp > Ri[i]) ex();

        ans[*itp] = i;
        rem_pos.erase(itp), rem_val.erase(i);

        while(!rem_pos.empty()){
            itp = rem_pos.lower_bound(Lu[i]);
            if(itp == rem_pos.end() or *itp > Ru[i]) break;

            int v = *(rem_val.rbegin());
            if(v < i) ex();

            ans[*itp] = v;
            rem_pos.erase(itp), rem_val.erase(v);
        }
    }

    while(!rem_pos.empty()){
        ans[*(rem_pos.begin())] = *rem_val.begin();
        rem_pos.erase(rem_pos.begin()), rem_val.erase(rem_val.begin());
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}