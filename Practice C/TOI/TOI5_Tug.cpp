#include<bits/stdc++.h>
using namespace std;
priority_queue <int,vector<int>,greater<int>> fi,se;
int n,ans=0;
main(){
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        fi.emplace(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        se.emplace(x);
    }
    while(n--){
        ans+= abs(fi.top()-se.top());
        fi.pop();
        se.pop();
    }
    cout << ans;
}
