#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
using ll = long long;
using pi = pair<int,int>;

int n,K,a[N];

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int> price;
    int not_island = 0;
    for(int i = 1, sum = 0; i <= n; i++){
        if(a[i] < 0){
            sum += 1-a[i];
            if(i == n or a[i+1] > 0){
                price.emplace_back(sum);
                sum = 0;
                not_island++;
            }
        }
    }
    //cout << not_island << "\n";
    sort(price.rbegin(), price.rend());
    int island = not_island-1, ans = 0;
    while(island > K){
        ans += price.back();
        price.pop_back();
        island--;
    }
    cout << ans << "\n";
    return 0;
}
