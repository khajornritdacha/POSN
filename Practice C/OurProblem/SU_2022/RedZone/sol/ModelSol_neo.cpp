#include <bits/stdc++.h>
#define DEBUG 1
#define st first
#define nd second
#define ll long long
#define mp make_pair
#define pi pair<int,int>
using namespace std;
typedef double db;
const int SZ=1e5+3;
const int MX=1e9+7;
const int MOD=1e9+7;

const int MAX=(int)1e6;
int house[SZ],val[SZ];

struct Sweep_Line {
    int pos,dam,id;
    bool operator<(const Sweep_Line &sox) const {
        return pos>sox.pos;
    }
};
vector <Sweep_Line> line;

void process(void) {
    int N,M,L,D;
    cin >> N >> M >> L >> D;
    for(int i=1;i<=N;i++) {
        cin >> house[i];
    }
    for(int i=1;i<=M;i++) {
        int bomb;
        cin >> bomb;
        int l=max(1,bomb-L);
        int r=min(N,bomb+L);
        line.push_back({l,-D,i});
        line.push_back({r+1,D,i});
    }
    sort(line.begin(),line.end());
    bool check_house=false;
    int sum=0;
    for(auto v:line) val[v.pos]+=v.dam;
    for(int i=1;i<=N;i++) {
        sum+=val[i];
        if(house[i]+sum>0) check_house=true;
    }
    if(check_house) {
        cout << -1;
        return ;
    }
    int l=1,r=M;
    while(l^r) {
        int mid=(l+r)>>1,sum=0;
        bool all_done=true;
        for(int i=1;i<=N+1;i++) val[i]=0;
        for(auto v:line) {
            if(v.id<=mid) {
                val[v.pos]+=v.dam;
            }
        }
        for(int i=1;i<=N;i++) {
            sum+=val[i];
            if(house[i]+sum>0) all_done=false;
        }
        if(all_done) r=mid;
        else l=mid+1;
    }
    cout << l;
    return ;
}

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int t(1);
    // cin >> t;
    while(t--) process();
}

/*
5 7 1
13 2 5 9 20
2 4
5 2
1 2
5 10
4 9
3 1
1 1
*/

// Sub 1 : N,M,L<=1000 -> 30 points
// Sub 2 : D=H(max) -> 20 points
// Sub 3 : ไม่มีเงื่อนไขเพิ่มเติม -> 50 points

/*
N,M <= 100,000
L <= N
1 <= Di <= 2,000
1 <= House[i] <= 2,000
1 <= Bomb[i] <= N
*/

/*
N,M <= 1e5
L <= N
1 <= Di <= 1e4
1 <= House[i] <= 1e9
1 <= Bomb[i] <= N
*/