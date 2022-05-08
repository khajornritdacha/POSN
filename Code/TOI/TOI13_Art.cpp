#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
using tu = tuple<int,int,int>;
const int N = 4e6+10, H = 1e6+10;
int n,T,ans,fen[H];
vector<tu> ep;
vector<int> point;
void up(int idx, int val){
    while(idx<=1e6){
        fen[idx]+=val;
        idx+=(idx&-idx);
    }
    return;
}
int sum(int idx){
    if(idx <= 0 or idx>1e6) return 0;
    int res = 0;
    while(idx){
        res+=fen[idx];
        idx-=(idx&-idx);
    }
    return res;
}
int big(int val){
    int l=1,r=1e6,mid,res=1;
    while(l<=r){
        mid = (l+r)/2;
        if(sum(mid)>=val){
            l = mid+1;
            res = max(res, mid);
        }else{
            r = mid-1;
        }
    }
    return res;
}
int bil(int val){
    int l=1, r=1e6, mid, res=1e6+1;
    while(l<=r){
        mid = (l+r)/2;
        if(sum(mid) <= val){
            r = mid-1;
            res = min(res, mid);
        }else{
            l = mid+1;
        }
    }
    return res;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> T;
    for(int i=1; i<=n; i++){
        int s,h,o,w;
        cin >> s >> h >> w >> o;
        ep.emplace_back(s, h, o);
        ep.emplace_back(s+w, h, -o);
        point.emplace_back(s);
        point.emplace_back(s+w);
    }
    sort(ep.begin(), ep.end());
    sort(point.begin(), point.end());
    point.resize(unique(point.begin(), point.end())-point.begin());
    int last = 0, idx = 0;
    for(int pos : point){
        int r = big(T);
        int l = bil(T);
        if(sum(l) == T and sum(r) == T)
            ans += (r-l+1)*(pos-last);
        if(idx < ep.size()){
            int now, h, co;
            tie(now, h, co) = ep[idx];
            //cout << "NOW : " << now << " " << h << " " << co << "\n";
            while(now == pos){
                up(1, co);
                up(h+1, -co);
                idx++;
                tie(now, h, co) = ep[idx];
            }
        }
        if(DEBUG){
            cout << "CUR : " << pos << " " << l << " " << r << " " << sum(l) << " " << sum(r) << "\n";
            for(int i=1; i<=10; i++){
                cout << sum(i) << " ";
            }
            cout << "\n";
            cout << "ANS : " << ans << "\n";
        }
        last = pos;
    }
    cout << ans << "\n";
}
