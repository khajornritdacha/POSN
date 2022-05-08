#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
int q,i;
struct cmp{
    bool operator()(const pi &a, const pi& b){
        if(a.first!=b.first)
            return a.first>b.first;
        return a.second<b.second;
    }
};
set<pi,cmp> ssp;
set<pi> ssf;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> q;
    while(q--){
        int c;
        cin >> c;
        if(c==1){
            int m;
            i++;
            cin >> m;
            ssp.insert({m,i});
            ssf.insert({i,m});
        }else if(c==2){
            pi temp = *ssf.begin();
            cout << temp.first << " ";
            ssf.erase(ssf.begin());
            int x=temp.first;
            temp.first = temp.second;
            temp.second = x;
            ssp.erase(temp);
        }else{
            pi temp = *ssp.begin();
            cout << temp.second << " ";
            ssp.erase(ssp.begin());
            int x=temp.first;
            temp.first = temp.second;
            temp.second = x;
            ssf.erase(temp);
        }
    }
}
