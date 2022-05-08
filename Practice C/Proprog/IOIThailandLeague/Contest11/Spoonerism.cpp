#include<bits/stdc++.h>
#define le(x) (int)(x).size()
using namespace std;

string str;
int t,sz1,st1,sz2,st2;

main(){
    cin >> t;
    while(t--){
        cin >> str;
        int n = str.size();
        for(int i=0; i<n; i++){
            int cnt = 0;
            while(i+cnt < n and (str[i+cnt] == 'a' or str[i+cnt] == 'e' or str[i+cnt] == 'i' or str[i+cnt] == 'o' or str[i+cnt] == 'u')){
                cnt++;
            }
            if(cnt != 0){
                st1 = i;
                sz1 = cnt;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            int cnt = 0;
            while(i-cnt >= 0 and (str[i-cnt] == 'a' or str[i-cnt] == 'e' or str[i-cnt] == 'i' or str[i-cnt] == 'o' or str[i-cnt] == 'u')){
                cnt++;
            }
            if(cnt != 0){
                st2 = i-cnt+1;
                sz2 = cnt;
                break;
            }
        }
        //cout << st1 << " " << sz1 << " " << st2 << " " << sz2 << "\n";
        if(st1 == st2){
            cout << str;
        }else{
            cout << str.substr(0, st1) << "" << str.substr(st2, sz2) << "" << str.substr(st1+sz1, st2-sz1-st1) << "" << str.substr(st1, sz1) << "" << str.substr(st2+sz2, n-st2-sz2) << "";
        }
        cout << "\n";
    }
}
