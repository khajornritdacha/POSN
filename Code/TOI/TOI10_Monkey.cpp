#include <bits/stdc++.h>
using namespace std;


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, n, K; cin >> m >> n >> K;
    int B[n+5] = {};
    bool vi[n+5] = {};

    for(int i = 1; i <= n; i++){
        cin >> B[i];
    }

    vector<pair<int,int>> bar;
    for(int i = 1; i <= K; i++){
        int h, p; cin >> p >> h;
        bar.emplace_back(h, p);
    }
    sort(bar.begin(), bar.end());

    int st = -1, mx = 0; cin >> st;
    bool use = false;
    vi[st-1] = vi[st] = vi[st+1] = true;
    for(auto [h, p] : bar){
        if(p == st)
            st = p+1;
        else if(p+1 == st)
            st = p;

        swap(vi[p], vi[p+1]); //forced to swap lane

        vi[st-1] = vi[st] = vi[st+1] = true; //use holy bar
    }

    for(int i = 1; i <= n; i++){
        if(vi[i]){
            if(B[i] > mx){
                mx = B[i];
                use = false;
                if(i != st){
                    use = true;
                }
            }
        }
    }

    cout << mx << "\n";
    cout << ((use) ? "USE" : "NO") << "\n";

    return 0;
}
