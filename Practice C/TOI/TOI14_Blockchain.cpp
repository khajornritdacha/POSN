#include<bits/stdc++.h>
using namespace std;
map<vector<pair<int,int>>,int> ump;
vector<pair<int,int>> a[10005];
int q,t;
main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> q;
    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        for(int j=0;j<n-1;j++){
            int x,y;
            cin >> x >> y;
            x--;y--;
            a[i].emplace_back(min(x,y),max(x,y));
        }
        sort(a[i].begin(),a[i].end());
        ump[a[i]]++;
    }
    for(int i=0;i<q;i++){
        int n;
        cin >> n;
        vector<pair<int,int>> b;
        for(int j=0;j<n-1;j++){
            int x,y;
            cin >> x >> y;
            x--;y--;
            b.emplace_back(min(x,y),max(x,y));
        }
        sort(b.begin(),b.end());
        if(ump.count(b)==0){
            cout << "0\n";
        }else{
            cout << ump[b] << "\n";
        }
    }
}
