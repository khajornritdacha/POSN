#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
string str[10];
vector<tuple<int,int,int,string>> vec;
int a[10][10],ans[10];
main(){
    for(int i=1; i<=4; i++){
        cin >> str[i];
    }
    for(int i=1; i<=4; i++){
        for(int j=1; j<=4; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=4; i++){
        int sum = 0,ova=0;
        for(int j=1; j<=4; j++){
            if(i == j) continue;
            if(a[i][j] > a[j][i])
                ans[i]+=3;
            else if(a[i][j] == a[j][i])
                ans[i]+=1;
            ova+=a[i][j]-a[j][i];
            sum+=a[i][j];
        }
        vec.emplace_back(ans[i], ova, sum, str[i]);
    }
    sort(vec.rbegin(), vec.rend());
    for(int i=0; i<vec.size(); i++){
        cout << get<3>(vec[i]) << " " << get<0>(vec[i]) << "\n";
    }
}
