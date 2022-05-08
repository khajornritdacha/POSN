#include <bits/stdc++.h>
using namespace std;

const int N = 101;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

vector<int> pr = {-1, -1, 0, 0, 1, 1}, pc[2];
int R,C,a[N][N];
bitset<5010> vi[N][N], di[10];
queue<tu> qq;


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }

    pc[0] = {0, 1, -1, 1, 0, 1}, pc[1] = {-1, 0, -1, 1, -1, 0};

    for(int i = 1; i <= 9; i++) for(int j = i; j < 5010; j += i) di[i][j] = true;

    for(int i : {-1, 0, 1}){
        int tmp = (R-1)/2+i;
        if(di[a[tmp][0]][1]){
            qq.emplace(1, tmp, 0);
            vi[tmp][0][1] = true;
        }
    }

    while(!qq.empty()){
        auto [dd, r, c] = qq.front(); qq.pop();
        //cout << dd << " " << r << " " << c << "\n";
        if(r == (R-1)/2 and c == C-1){
            cout << dd << "\n";
            return 0;
        }

        if(dd > 5000) continue;

        int cur = r&1;
        for(int i = 0; i < 6; i++){
            int gr = r+pr[i], gc = c+pc[cur][i];
            if(gr < 0 or gr >= R or gc < 0 or gc >= C) continue;
            if(a[gr][gc] == 0) continue;
            if(vi[gr][gc][dd+1]) continue;
            if(di[a[gr][gc]][dd+1]){
                qq.emplace(dd+1, gr, gc);
                vi[gr][gc][dd+1] = true;
            }
        }
    }

    //assert(0);
    return 0;   
}