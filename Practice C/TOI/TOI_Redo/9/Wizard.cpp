#include <bits/stdc++.h>
using namespace std;

const int N = 1510, INF = 1e9;
using ll = long long;
using pi = pair<int, int>;
using tu = tuple<int,int,int,int>;

int wx,wy,n,x[4][N],y[4][N];
vector<tu> vec;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> wx >> wy >> n;
    for(int k = 0; k <= 3; k++){
        for(int i = 1; i <= n; i++){
            cin >> x[k][i] >> y[k][i];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            vec.emplace_back(x[0][i] + x[1][j], y[0][i] + y[1][j], i, j);
        }
    }

    sort(vec.begin(), vec.end());

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int tx = wx - x[2][i] - x[3][j], ty = wy - y[2][i] - y[3][j];
            tu tmp = *lower_bound(vec.begin(), vec.end(), tu(tx, ty, 0, 0));
            if(get<0>(tmp) == tx and get<1>(tmp) == ty){
                int k = get<2>(tmp), l = get<3>(tmp);
                cout << x[0][k] << " " << y[0][k] << "\n" << x[1][l] << " " << y[1][l] << "\n" << x[2][i] << " " << y[2][i] << "\n" << x[3][j] << " " << y[3][j] << "\n";
                return 0;
            }
        }
    }
    return 0;
}