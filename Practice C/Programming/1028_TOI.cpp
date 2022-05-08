#include<bits/stdc++.h>
using namespace std;
int cnt[30];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        char c,a,b;
        int x;
        cin >> c;
        if(c == '!'){
            cout << "!\n";
            return 0;
        }
        if(c == '='){
            cin >> a >> x;
            cnt[a-'A']+=x;
        }else if(c == '#'){
            cin >> a;
            cout << cnt[a-'A'] << "\n";
        }else{
            cin >> a >> b;
            if(c == '+')
                cnt[a-'A']+=cnt[b-'A'];
            else if(c == '-')
                cnt[a-'A']-=cnt[b-'A'];
            else if(c == '*')
                cnt[a-'A']*=cnt[b-'A'];
            else if(c == '/' and cnt[b-'A'] != 0)
                cnt[a-'A']/=cnt[b-'A'];
        }
    }
}
