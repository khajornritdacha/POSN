#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+10;

int n,Q,fro[N],rea[N];

///https://atcoder.jp/contests/abc225/tasks/abc225_d

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> Q;

    for(int i = 1; i <= n; i++) fro[i] = rea[i] = -1;

    for(int i = 1; i <= Q; i++){
        int code;
        cin >> code;
        if(code == 1){ ///Connect y to x
            int x,y; cin >> x >> y;
            fro[y] = x;
            rea[x] = y;
        }else if(code == 2){ ///Disconnect y from x
            int x,y; cin >> x >> y;
            fro[y] = -1;
            rea[x] = -1;
        }else{ ///Ask
            int x; cin >> x;
            int u = x;

            deque<int> dq;
            while(u != -1){
                dq.push_front(u);
                u = fro[u];
            }

            u = rea[x];
            while(u != -1){
                dq.push_back(u);
                u = rea[u];
            }

            cout << dq.size() << " ";
            for(int dd : dq) cout << dd << " ";
            cout << "\n";
        }
    }
    return 0;
}
