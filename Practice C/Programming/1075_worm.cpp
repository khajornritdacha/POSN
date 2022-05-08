#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
long long temp,elec,sum,ans1,ans2,mx;
int n;
vector<pi> vec;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        vec.emplace_back(y,x);
    }
    sort(vec.begin(),vec.end());
    for(int i=0; i<n; i++){
        elec = vec[i].first;
        sum+=vec[i].second;
        temp = sum*100000/elec;
        if(temp>mx){
            mx=temp;
            ans1=sum;
            ans2=elec;
        }else if(temp==mx){
            if(elec<ans2){
                ans1=sum;
                ans2=elec;
            }
        }
    }
    cout << ans1 << " " << ans2;
}

