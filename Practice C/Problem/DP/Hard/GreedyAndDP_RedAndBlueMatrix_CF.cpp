#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;

///https://codeforces.com/problemset/problem/1606/D

int n,m;
vector<pair<vector<int>, int>> a;
vector<vector<int>> tl,tr,bl,br; ///Maximum and Minimum from each corner
char ans[N];

///sort array by its first column element
///After sorted, it can be seen that max of top left < min of bottom left
///And min of top right > max of top left

void test_case(){
    cin >> n >> m;
    a.clear(); tl.clear(); tr.clear(); bl.clear(); br.clear();

    for(int i = 0; i <= n; i++){
        vector<int> tmp(m+1);
        if(i == 0){ a.emplace_back(tmp, 0); continue; }
        for(int j = 1; j <= m; j++){
            cin >> tmp[j];
        }
        a.emplace_back(tmp, i);
    }

    sort(a.begin(), a.end());

    tl.resize(n+2); tr.resize(n+2); bl.resize(n+2); br.resize(n+2);

    tl[0].resize(m+5, 0); tr[0].resize(m+5, 1e9); bl[0].resize(m+5, 1e9); br[0].resize(m+5, 0);
    tl[n+1].resize(m+5, 0); tr[n+1].resize(m+5, 1e9); bl[n+1].resize(m+5, 1e9); br[n+1].resize(m+5, 0);

    for(int i = 1; i <= n; i++){ tl[i].resize(m+5, 0); for(int j = 1; j <= m; j++) tl[i][j] = max({tl[i-1][j], tl[i][j-1], a[i].first[j]}); }
    for(int i = 1; i <= n; i++){ tr[i].resize(m+5, 1e9); for(int j = m; j >= 1; j--) tr[i][j] = min({tr[i-1][j], tr[i][j+1], a[i].first[j]}); }
    for(int i = n; i >= 1; i--){ bl[i].resize(m+5, 1e9); for(int j = 1; j <= m; j++) bl[i][j] = min({bl[i+1][j], bl[i][j-1], a[i].first[j]}); }
    for(int i = n; i >= 1; i--){ br[i].resize(m+5, 0); for(int j = m; j >= 1; j--) br[i][j] = max({br[i+1][j], br[i][j+1], a[i].first[j]}); }

    //cout << "CHECK\n";
    bool ok = false; int col = -1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < m; j++){
            if(tl[i-1][j] < bl[i][j] and tr[i-1][j+1] > br[i][j+1]){
                for(int k = 1; k <= i-1; k++) ans[a[k].second] = 'B';
                for(int k = i; k <= n; k++) ans[a[k].second] = 'R';
                col = j;
                ok = true;
                break;
            }
        }
        if(ok) break;
    }

    if(ok){
        cout << "YES\n";
        for(int i = 1; i <= n; i++){
            cout << ans[i];
        }
        cout << " " << col << "\n";
    }else{
        cout << "NO\n";
    }

    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
