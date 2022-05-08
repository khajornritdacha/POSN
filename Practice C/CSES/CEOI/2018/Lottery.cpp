#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;

//observe that we can reduce number of comparisons
//after that it is required to reduce space consumption 

int n, L, arr[N], pre[N], qs[N][110], ans[N][110], Q, tot;
vector<pair<int, int>> qq;

void cal(int cur){
    vector<int> chua[N];
    for(int i = cur+1; i <= tot; i++){
        if(i == cur) continue;
        chua[pre[i]].emplace_back(i);
    }
    for(int i = 0, j = 0; i < Q; i++){
        while(j <= L and j <= qq[i].first){
            qs[cur][i] += chua[j].size();
            for(int cc : chua[j]) qs[cc][i]++;
            j++;
        }
        if(i != 0) qs[cur][i] += qs[cur][i-1];
    }
}

int main(void){
    cin >> n >> L;
    for(int i =1; i <= n; i++){
        cin >> arr[i];
    }
    cin >> Q;
    for(int i = 1; i <= Q; i++){
        int k; cin >> k;
        qq.emplace_back(k, i);
    }
    sort(qq.begin(), qq.end());

    tot = n-L+1;
    for(int i = 1; i <= L; i++){
        for(int j = i+1, k = 2; k <= tot; j++, k++){
            pre[k] += (arr[i] != arr[j]);            
        }
    }
    cal(1);


    for(int i = 2; i <= tot; i++){
        for(int j = tot; j >= i+1; j--){
            int tmp = -1*(arr[i-1] != arr[j-1]) + (arr[i+L-1] != arr[j+L-1]);
            pre[j] = pre[j-1] + tmp;
        }
        cal(i);
    }

    for(int i = 1; i <= tot; i++){
        for(int j = 0; j < Q; j++){
            ans[i][qq[j].second] = qs[i][j];
        }
    }
    for(int i = 1; i <= Q; i++){
        for(int j = 1; j <= tot; j++){
            cout << ans[j][i] << " ";
        }
        cout << "\n";
    }
}