#include <bits/stdc++.h>
using namespace std;
map < string,bool> top;
vector<string> vec;
int n;
string str;
main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> str;
        if(top[str]==false){
            vec.push_back(str);
            top[str] = true;
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << endl;
    }
    return 0;
}
