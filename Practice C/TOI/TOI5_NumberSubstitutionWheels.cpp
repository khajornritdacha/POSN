#include<bits/stdc++.h>
using namespace std;
string str;
int top[5];
char start[5];
vector<int> ans;
void up(int idx){
    if(idx != 1){
        top[idx]+=(start[idx]-'0');
        if(top[idx]>9)
            top[idx]-=9;
    }else{
        top[idx]--;
        if(top[idx] == 0)
            top[idx] = 9;
    }
}
main(){
    for(int i=0; i<3; i++){
        cin >> start[i];
        top[i] = start[i]-'0';
    }
    cin >> str;
    for(int idx = 0; idx<str.size(); idx++){
        int now = str[idx]-'0';
        //cout << "IDX : " << idx << "\n";
        for(int i=0; i<=2; i++){
            //cout << top[i] << " \n"[i==2];
            now = top[i]+now-1;
            if(now>9)
                now-=9;
            up(i);
        }
        ans.emplace_back(now);
    }
    for(int an : ans)
        cout << an;
}
