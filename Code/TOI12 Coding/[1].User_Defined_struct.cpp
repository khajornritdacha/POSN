#include<bits/stdc++.h>
using namespace std;
struct mm{
    int a,b;
    bool operator<(const mm& temp){
        if(a!=temp.a) return a<temp.a;
        return b<temp.b;
    }
};
vector<mm> vec;
int n;
main(){
    cin >> n;
    vec.resize(n);
    for(int i=0; i<n; i++){
        cin >> vec[i].a >> vec[i].b;
    }
    sort(vec.begin(),vec.end());
    for(int i=0; i<n; i++)
        cout << vec[i].a << " " << vec[i].b << "\n";
}
