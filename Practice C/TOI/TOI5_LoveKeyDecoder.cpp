#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
vector<int> ans[35];
vector<tuple<int,int,int,int>> vec[5];
int n;
char str[30];
main(){
    vec[1].emplace_back(0,0,0,1);
    vec[1].emplace_back(1,1,1,2);
    vec[2].emplace_back(1,0,0,3);
    vec[2].emplace_back(0,1,1,4);
    vec[3].emplace_back(1,1,0,1);
    vec[3].emplace_back(0,0,1,2);
    vec[4].emplace_back(1,0,1,4);
    vec[4].emplace_back(0,1,0,3);
    cin >> n;
    int u = 1;
    for(int te=1; te<=n; te++){
        cin >> str+1;
        int len = strlen(str+1);
        if(len!=16){
            n--;
            break;
        }
        for(int i=1; i<=15; i+=2){
            int c1=str[i]-'0', c2=str[i+1]-'0';
            for(int j=0; j<vec[u].size(); j++){
                int p1,p2,g,v;
                tie(p1,p2,g,v) = vec[u][j];
                if(c1==p1 and c2==p2){
                    ans[te].emplace_back(g);
                    u = v;
                    break;
                }
            }
        }
        if(DEBUG){
            for(int i=0; i<ans[te].size(); i++)
                cout << ans[te][i];
            cout << "\n";
        }
    }
        map<vector<int>, int> mp;
        for(int bit = 'A'; bit<='Z'; bit++){
            vector<int> pat;
            for(int i=7; i>=0; i--){
                if(bit&(1<<i))
                    pat.emplace_back(1);
                else
                    pat.emplace_back(0);
            }
            mp[pat] = bit;
        }
        for(int i=1; i<=n; i++){
            cout << (char)mp[ans[i]];
        }

}
