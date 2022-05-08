#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> vec;
vector<string> tem={"Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};
vector<int> pe={0,1,2,3,4,5,6,7};
int n;
string str1,str2,waste;
map<pair<string,string>,int> mp;
main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> str1;
        for(int j=0; j<4; j++)
            cin >> waste;
        cin >> str2;
        if(str1>str2) swap(str1,str2);
        mp[{str1,str2}]++;
        //cout << str1 << " " << str2 << "\n";
    }
    do{
        int cnt=0;
        for(int i=0; i<7; i++){
            str1=tem[pe[i]];
            str2=tem[pe[i+1]];
            if(str1>str2) swap(str1,str2);
            if(mp.find({str1,str2})!=mp.end()){
                cnt++;
            }
        }
        if(cnt==n){
            //cout << "wow" << "\n\n";
            vector<string> temporary;
            for(int i=0; i<8; i++)
                temporary.emplace_back(tem[pe[i]]);
            vec.emplace_back(temporary);
        }
    }while(next_permutation(pe.begin(),pe.end()));
    sort(vec.begin(),vec.end());
    //cout << vec.size() << "\n\n";
    for(string ss : vec[0])
        cout << ss << "\n";
}
