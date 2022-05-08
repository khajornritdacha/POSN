#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using pi = pair<ll,ll>;
ll K,N;
vector<ll> fen;
vector<pi> point;
void build(){
    fen.clear();
    fen.resize(100100, 0);
}
void up(int i, int val){
    while(i<=1e5+10){
        fen[i]+=val;
        i+=i&-i;
    }
}
ll qs(int i){
    ll tmp = 0;
    if(i<=0) return 0;
    while(i>=1){
        tmp+=fen[i];
        i-=i&-i;
    }
    return tmp;
}
ll check(int chk){
    build();
    ll sum = 0;
    for(int i=1; i<=N; i++)
        up(point[i].second, 1);
    int right_ptr=1, left_ptr=1;
    while(left_ptr<=N){
        while(point[right_ptr].first - point[left_ptr].first <= chk && right_ptr<=N){
            up(point[right_ptr].second, -1);
            right_ptr++;
        }
        sum += right_ptr-left_ptr-1;
        sum += qs(min(100000ll,point[left_ptr].second+chk))-qs(max(0ll,point[left_ptr].second-chk-1));
        left_ptr++;
    }
    return sum;
}
int main() {
    cin >> N >> K;
    int ans = 1e9;
    point.emplace_back(0,0);
    for(int i=1; i<=N; i++){
        int x,y;
        cin >> x >> y;
        point.emplace_back(x,y);
    }
    sort(point.begin(), point.end());
    int l=0, r=1e5+10, mid;
    while(l<=r){
        mid = (l+r)/2;
        if(check(mid) >= K){
            r = mid-1;
            ans = min(ans, mid);
        }else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
    return 0;
}
