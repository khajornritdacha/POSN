#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
using pi = pair<int,int>;
deque< pi > dq;
int n,a[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){

        if(!dq.empty() and a[i] >= dq.front().first){
            for(int j=dq.front().second; j<i; j++){
                cout << dq.front().first << " ";
            }
            dq.clear();
        }

        while(!dq.empty() and a[i] >= dq.back().first){
            dq.pop_back();
        }

        dq.emplace_back(a[i], i);
    }

    if(dq.size() > 1){
        for(int i=1; i<dq.size(); i++){
            for(int j=dq[i-1].second; j<dq[i].second; j++){
                cout << dq[i].first << " ";
            }
        }
    }
}
