#include<bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> pq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        char code;
        cin >> code;
        if(code == 'P'){
            int x;
            cin >> x;
            pq.emplace(x);
        }else{
            if(!pq.empty()){
                cout << pq.top() << "\n";
                pq.pop();
            }else{
                cout << "-1\n";
            }
        }
    }
}
