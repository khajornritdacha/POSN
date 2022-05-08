#include <bits/stdc++.h>
#include "rumors.h";
#define DEBUG 0
using namespace std;

vector<int> analyze_rumors(int N, int K, int Q, vector<int> D, vector<int> X, vector<int> J){
    vector<int> ans(Q), qs(N);
    int res[N][N] = {};
    deque<tuple<int,int,int>> mn[N];
    vector<vector<pair<int,int>>> qq(N);

    for(int i = 0; i < Q; i++){
        qq[X[i]].emplace_back(J[i], i);
    }
    for(int i = 1; i < N; i++){
        qs[i] = qs[i-1];
        qs[i] += (D[i]-D[i-1]-1)/K;
    }

    if(DEBUG){
        for(int i = 0; i < N; i++){
            cout << qs[i] << " \n"[i==N-1];
        }
    }

    for(int i = 0; i < N; i++){ //precalculate ans for each size
        for(int j = 0; j < N; j++){
            while(!mn[j].empty() and i > get<2>(mn[j].front())) mn[j].pop_front(); //remove interval that i doesn't belong
            
            if(i+j < N){ //cost from i to j is qs[i+j]-qs[i]
                int cost = qs[i+j]-qs[i];
                while(!mn[j].empty() and cost <= get<0>(mn[j].back())) mn[j].pop_back(); //push minimum
                mn[j].emplace_back(cost, i, i+j);
            }
        }
        
        for(int j = 0; j < N; j++) res[i][j] = get<0>(mn[j].front());

        if(DEBUG){
            cout << "CUR : " << i << "\n";
            for(int j = 0; j < N; j++) cout << res[i][j] << " ";
            cout << "\n";
        }

        for(int j = N-1; j >= 1; j--){
            if(res[i][j] <= res[i][j-1]){
                res[i][j-1] = res[i][j];
            }
        }

        for(auto [val, idx] : qq[i]){
            ans[idx] = (upper_bound(res[i], res[i]+N, val)-res[i]); 
        }
    }

    return ans;
}

// int main(void){
//     int N, K, Q; cin >> N >> K >> Q;
//     vector<int> d(N), x(Q), j(Q);
//     for(int i = 0; i < N; i++){
//         cin >> d[i];
//     }
//     for(int i = 0; i < Q; i++){
//         cin >> x[i] >> j[i];
//     }

//     vector<int> ans = analyze_rumors(N, K, Q, d, x, j);

//     for(int i = 0; i < Q; i++){
//         cout << ans[i] << " ";
//     }
//     cout << "\n";

//     return 0;
// }