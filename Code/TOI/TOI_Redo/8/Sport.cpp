#include <bits/stdc++.h>
using namespace std;

const int N = 210, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int K;
char ans[N];

void solve(int W1, int W2, int lv = 0){
    if(W1 == K or W2 == K){
        for(int i = 0; i < lv; i++) cout << ans[i] << " ";
        cout << "\n";
        return;
    }

    ans[lv] = 'W';
    solve(W1+1, W2, lv+1);

    ans[lv] = 'L';
    solve(W1, W2+1, lv+1);
}

int main(void){
    int a, b;
    cin >> K >> a >> b;

    solve(a, b);

    return 0;
}