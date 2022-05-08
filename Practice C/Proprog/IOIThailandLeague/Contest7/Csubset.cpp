#include<bits/stdc++.h>
using namespace std;

string str;
int cnt;
main(){
    cin >> str;
    if(str.size() == 2){
        cout << 1;
        return 0;
    }
    for(int i=0; i<str.size(); i++){
        if(str[i] == ',')
            cnt++;
    }
    cout << (1ll<<(cnt+1));
}
