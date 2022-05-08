#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans,found;
vector< pair<long long,long long> > vec;
/*bool sortfir(const pair<long long> &x, const pair<long long> &y){
    return (x.first > y.first);
}*/
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        found = 0;
        for(int j=0;j<vec.size();j++){
            if(a==vec[j].second){
                vec[j].first++;
                found = 1;
            }
        }
        if(found==0){
            vec.push_back({1,a});
        }
    }
    sort(vec.begin(),vec.end());
   /* for(int i=0;i<vec.size();i++){
        cout << vec[i].second << " " << vec[i].first << '\n';
    }*/
    cout << vec[vec.size()-1].first;
}
