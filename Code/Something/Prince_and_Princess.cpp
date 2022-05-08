#include<bits/stdc++.h>
using namespace std;
vector<bool> used;
int t;
set <int> jaoset[100005],yingset[100005];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        used.emplace_back(false);
        for(int i=1;i<=n;i++){
            jaoset[t].insert(i);
            yingset[t].insert(i);
            used.emplace_back(false);
        }
        for(int i=1;i<=n;i++){
            int kon,code = 0;
            cin >> kon;
            for(int j=1;j<=kon;j++){
                int jao;
                cin >> jao;
                if(used[jao]==false&&code==0){
                    used[jao] = true;
                    //cout << jao << " " << j << " ";
                    jaoset[t].erase(jao);
                    yingset[t].erase(i);
                    code = 1;
                }
            }
        }
        if(jaoset[t].size()!=0){
            cout << "IMPROVE\n" << *yingset[t].begin() << " " << *jaoset[t].begin() << "\n";
        }else{
            cout << "OPTIMAL\n";
        }
        used.clear();
    }
}
