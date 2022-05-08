#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;

int main(void){
    int n,M;
    cin >> n >> M;
    vector<pi> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i].first;
        vec[i].second = i+1;
    }
    sort(vec.begin(), vec.end());

    int l = 0, r = n-1, ans = -1;
    while(l <= r){
        int mid = (l+r)>>1;

        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(vec[i].first <= vec[j].first) continue;
                if(vec[j].second < vec[i].second and vec[i].second-vec[j].second <= mid)
                    dp[i] = max(dp[i], dp[j]+1);

                if(vec[j].second > vec[i].second and vec[i].second+n-vec[j].second <= mid)
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }

        /*cout << "K : " << mid << "\n";
        for(int d : dp)
            cout << d << " ";
        cout << "\n";*/

        if(*max_element(dp.begin(), dp.end()) >= M){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }

    cout << ans << "\n";
    return 0;
}
