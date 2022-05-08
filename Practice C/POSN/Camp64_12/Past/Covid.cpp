#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 1e5+10;
struct covid{
    int bed,patient;
};
map<int,covid> mp;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        int x,code;
        string str;
        cin >> str;
        if(str == "exit")
            break;
        if(str == "area" or str == "bed"){
            cin >> code >> x;
            mp[code].bed += x;
        }else if(str == "patient"){
            cin >> code >> x;
            mp[code].patient += x;
        }else if(str == "death"){
            cin >> code >> x;
            mp[code].patient -= x;
        }else if(str == "recovery"){
            cin >> code >> x;
            mp[code].patient -= x;
        }else if(str == "report"){
            cin >> code;
            if(code != 0){
                if(mp.find(code) != mp.end()){
                    cout << code << " " << mp[code].bed-mp[code].patient << "\n";
                }else{
                    cout << "no area " << code << "\n";
                }
            }else{
                for(auto it = mp.begin(); it!=mp.end(); it++){
                    cout << it->first << " " << (it->second).bed-(it->second).patient << "\n";
                }
            }
        }
    }
}
