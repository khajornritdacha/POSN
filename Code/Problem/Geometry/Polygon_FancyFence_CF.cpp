#include<bits/stdc++.h>
using namespace std;
int t;
vector<int> poly;
void gen(){
    for(int i=3; ; i++){
        //cout << i << " ";
        long long temp=(long long)(i-2)*180;
        if(temp/i*i==temp){
            poly.emplace_back(temp/i);
            //cout << poly.back() << " ";
        }
        if(temp/i>=179) break;
    }
}
main(){
    cin >> t;
    gen();
    while(t--){
        int angle;
        bool cd=false;
        cin >> angle;
        for(int i=0; i<poly.size(); i++){
            if(angle==poly[i]){
                cout << "YES\n";
                cd=1;
                break;
            }
        }
        if(!cd) cout << "NO\n";
    }
}
