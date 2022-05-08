#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,ans;
string str;
main(){
    cin >> n >> str;
    for(; 1;){
        int cnt = 0;
        for(int j=0; j+1<str.size(); j++){
            if(str[j] == 'M' and str[j+1] == 'F'){
                swap(str[j], str[j+1]);
                cnt++;
                j++;
            }
        }
        if(cnt > 0)
            ans++;
        else
            break;
    }
    cout << ans;
}
