#include<bits/stdc++.h>
using namespace std;
vector<tuple<int,int,int,int>> vec;
int a[5][5],tg[5],se[5],fi[5];
string str[10];
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
        for(int j=1; j<=4; j++){
            if(i==j) continue;
            tg[i] += a[i][j];
            se[i] += a[i][j]-a[j][i];
            if(a[i][j] > a[j][i])
                fi[i]+=3;
            else if(a[i][j] == a[j][i])
                fi[i]++;
        }
        vec.emplace_back(fi[i],se[i],tg[i],i);
    }
    sort(vec.rbegin(), vec.rend());
    for(int i=0; i<vec.size(); i++){
        cout << str[get<3>(vec[i])] << " " << get<0>(vec[i]) << "\n";
    }
}
