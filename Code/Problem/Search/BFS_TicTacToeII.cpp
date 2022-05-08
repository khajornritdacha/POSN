#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

using grid = vector<vector<char>>;
map<grid, bool> vi,win;
queue<pair<grid, char>> qq;

///https://www.spoj.com/problems/TOE2/

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    grid st;
    st.resize(3, vector<char>(3, '.'));
    qq.emplace(st, 'X');
    while(!qq.empty()){
        grid now;
        char cur;
        tie(now, cur) = qq.front();
        qq.pop();

        if(vi[now]) continue;
        vi[now] = true;
        bool ok = false;

        for(int i=0; i<3; i++){
            int cnt = 0;
            for(int j=0; j<3; j++){
                if(now[i][0] != '.' and now[i][j] == now[i][0]) cnt++;
            }
            if(cnt == 3)
                ok = true;
        }

        for(int j=0; j<3; j++){
            int cnt = 0;
            for(int i=0; i<3; i++){
                if(now[0][j] != '.' and now[i][j] == now[0][j]) cnt++;
            }
            if(cnt == 3)
                ok = true;
        }

        if(now[0][0] != '.' and now[0][0] == now[1][1] and now[1][1] == now[2][2])
            ok = true;
        if(now[0][2] != '.' and now[0][2] == now[1][1] and now[1][1] == now[2][0])
            ok = true;

        if(ok){
            win[now] = true;
            continue;
        }

        int tmp = 0;

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(now[i][j] != '.') continue;
                char pre = now[i][j];
                now[i][j] = cur;
                qq.emplace(now, (cur == 'X' ? 'O' : 'X'));
                now[i][j] = pre;
                tmp++;
            }
        }

        if(tmp == 0){
            win[now] = true;
        }
    }

    while(true){
        string str;
        cin >> str;
        if(str == "end") break;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                st[i][j] = str[i*3+j];
            }
        }

        if(DEBUG){
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    cout << st[i][j];
                }
                cout << "\n";
            }
            cout << "\n";
        }

        if(win.find(st) != win.end())
            cout << "valid";
        else
            cout << "invalid";
        cout << "\n";
    }
}
