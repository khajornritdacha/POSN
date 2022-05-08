#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> pq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=2;i<n;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]){
            pq.push_back(a[i]);
        }
    }
    if(a[1]>a[2]) pq.push_back(a[1]);
    if(a[n]>a[n-1]) pq.push_back(a[n]);
    sort(pq.begin(),pq.end(),greater<int>());
    if(pq.empty()){ cout << "-1"; return 0;}
    int cnt=0,x=0;
    vector<int> vec;
    for(auto z:pq){
        if(x!=z){
            vec.push_back(z);
            x = z;
            cnt++;
            if(cnt==k)
                break;
        }
    }
    if(vec.size()<k){
        for(int i=vec.size()-1;i>=0;i--){
            cout << vec[i] << '\n';
        }
    }else{
        for(int x:vec)
            cout << x << "\n";
    }
}
