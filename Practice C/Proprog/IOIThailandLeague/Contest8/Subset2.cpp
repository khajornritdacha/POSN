#include<bits/stdc++.h>
using namespace std;

string str;
int pa,cnt;

main(){
    cin >> str;
    if(str.size() == 2){
        cout << 1;
        return 0;
    }
    for(int i=1; i+1<str.size(); i++){
        if(str[i] == '}')
            pa--;
        if(str[i] == '{')
            pa++;
        if(pa > 0) continue;
        if(str[i] == ',')
            cnt++;
    }
    cout << (1ll<<(cnt+1));
}
