#include <bits/stdc++.h>
using namespace std;

//https://oj.uz/problem/view/JOI19_ho_t2
//greedy by choose the current picture and frame if they are compatible from backward

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    vector<pair<int,int>> pic(n); 
    vector<int> frame(m);

    for(auto &[a, b] : pic) cin >> b >> a;
    for(int &a : frame) cin >> a;

    sort(pic.begin(), pic.end()), sort(frame.begin(), frame.end());

    int ans = 0;
    for(int i = n-1, j = m-1; i >= 0 and j >= 0; i--){
        if (pic[i].second <= frame[j]){
            ans++;
            j--;
        }
    }
    
    cout << ans << "\n";

    return 0;
}