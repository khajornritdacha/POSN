#include<bits/stdc++.h>
using namespace std;

using grid = vector<vector<char>>;
map<grid, bool> vi;
queue<pair<grid, char>> qq;
///https://www.spoj.com/problems/TOE1/
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

        if(ok)
            continue;


        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(now[i][j] != '.') continue;
                char pre = now[i][j];
                now[i][j] = cur;
                qq.emplace(now, (cur == 'X' ? 'O' : 'X'));
                now[i][j] = pre;
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cin >> st[i][j];
            }
        }
        char wa;
        //cin >> wa;
        if(vi.find(st) != vi.end())
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }
}
