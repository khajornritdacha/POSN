#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
int n,pos[200100],a[200100];
vector<pi> vec;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vec.emplace_back(0,0);
    for(int i=1; i<=n; i++){
        cin >> a[i];
        vec.emplace_back(a[i],i);
    }
    sort(vec.begin(),vec.end());
    for(int i=1; i<=n; i++){
        pos[vec[i].second]=i;
    }
    for(int i=1; i<=n; i++){
        //cout << pos[i] << " ";
        if(pos[i]==n/2){
            cout << vec[n/2+1].first << "\n";
        }else if(pos[i]==n/2+1){
            cout << vec[n/2].first << "\n";
        }else if(pos[i]<n/2){
            cout << vec[n/2+1].first << "\n";
        }else{
            cout << vec[n/2].first << "\n";
        }
    }
}
