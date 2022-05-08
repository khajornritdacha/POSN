#include<bits/stdc++.h>
using namespace std;

using pi = pair<int,int>;
vector< pi > vec;
int n,H,T;

bool chk(int W){
    deque< pi > mn, mx;
    for(int i=0; i<vec.size(); i++){
        int nx,ny;
        tie(nx, ny) = vec[i];

        while(!mx.empty() and nx-mx.front().first > W)
            mx.pop_front();
        while(!mn.empty() and nx-mn.front().first > W)
            mn.pop_front();

        while(!mx.empty() and ny >= mx.back().second)
            mx.pop_back();
        while(!mn.empty() and ny <= mn.back().second)
            mn.pop_back();

        mx.emplace_back(nx, ny);
        mn.emplace_back(nx, ny);

        if(mx.front().second-mn.front().second >= H)
            return true;
    }

    return false;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        vec.clear();
        cin >> n >> H;
        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            vec.emplace_back(x, y);
        }
        sort(vec.begin(), vec.end());
        int l=0, r=1e7, mid, ans = 1e9;
        while(l <= r){
            mid = (l+r)/2;
            if(chk(mid)){
                ans = min(ans, mid);
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        if(ans == 1e9)
            ans = -1;
        cout << ans << "\n";
    }
}
