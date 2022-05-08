#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<int, int>;
vector<int> vec;
int n,K,cnt;

void solve(int lv = 1, int la = 1, int ch = 0){
    //cout << lv << " " << la << " " << ch << "\n";
    if(lv == n+1){
        //cnt++;
        if(ch == K){
            for(int now : vec)
                cout << now << " ";
            cout << "\n";
        }
        return;
    }

    if(ch == K){
        solve(lv+1, la, ch);
        return;
    }

    for(int i=la; i<=n; i++){
        if(n-i+1 >= K-ch){
            cnt++;
            vec.emplace_back(i);
            solve(lv+1, i+1, ch+1);
            vec.pop_back();
        }
    }
}

main(){
    cin >> n >> K;
    solve();
    cout << "CALL : " << cnt << " times\n";
}
