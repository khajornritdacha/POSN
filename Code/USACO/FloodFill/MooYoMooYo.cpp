#include<bits/stdc++.h>
#define int long long
#define DEBUG false
using namespace std;

const int N = 1e2+10;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

char a[N][N];
int n,cnt,K;
bool vi[N][N],mark[N][N];
///http://www.usaco.org/index.php?page=viewproblem2&cpid=860
void flood(int ssr, int ssc, int code){
    int pr[]={-1,1,0,0},pc[]={0,0,-1,1};
    queue<pi> qq;
    qq.emplace(ssr, ssc);
    while(!qq.empty()){
        auto [nr, nc] = qq.front();
        qq.pop();
        vi[nr][nc] = true;
        char pre = a[nr][nc];

        if(code == 1){
            a[nr][nc] = '0';
        }
        cnt++;

        for(int i=0; i<4; i++){
            int gr = nr+pr[i], gc = nc+pc[i];
            if(gr < 1 or gr > n or gc < 1 or gc > 10) continue;
            if(vi[gr][gc]) continue;
            if(a[gr][gc] == '0') continue;
            if(a[gr][gc] == pre){
                qq.emplace(gr, gc);
                vi[gr][gc] = true;
            }
        }
    }
}

bool chk(){
    bool ok = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=10; j++){
            if(a[i][j] != '0' and !vi[i][j]){
                cnt = 0;
                flood(i, j, 0);
                //cout << "St : " << i << " " << j << " " << cnt << "\n";
                if(cnt >= K){
                    ok = true;
                    mark[i][j] = true;
                }
            }
        }
    }

    if(DEBUG){
        cout << "CHK : " << ok << "\n";
    }

    return ok;
}


void del(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=10; j++){
            if(mark[i][j]){
                flood(i, j, 1);
            }
        }
    }
}

void drop(){
    for(int j=1; j<=10; j++){
        int pr = n, ps = n;
        for(int i=n; i>=1; i--){
            if(a[i][j] == '0'){
                pr = ps = i;
                break;
            }
        }

        for(int i=pr; i>=1; i--){
            if(a[i][j] != '0'){
                a[pr][j] = a[i][j];
                pr--;
                a[i][j] = '0';
            }
        }
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); freopen("mooyomooyo.in", "r", stdin); freopen("mooyomooyo.out", "w", stdout);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=10; j++){
            cin >> a[i][j];
        }
    }

     if(DEBUG){
        cout << "\nINPUT\n";
        for(int i=1; i<=n; i++){
            for(int j=1; j<=10; j++){
                cout << a[i][j];
            }
            cout << "\n";
        }
        cout << "--------------------\n";
    }

    while(true){
        memset(mark, 0, sizeof(mark));
        memset(vi, 0, sizeof(vi));
        if(!chk())
            break;

        memset(vi, 0, sizeof(vi));
        del();

        if(DEBUG){
            cout << "--------------------\n";
            cout << "DEL\n";
            for(int i=1; i<=n; i++){
                for(int j=1; j<=10; j++){
                    cout << a[i][j];
                }
                cout << "\n";
            }
            cout << "\n";
        }

        drop();

        if(DEBUG){
            cout << "DROP\n";
            for(int i=1; i<=n; i++){
                for(int j=1; j<=10; j++){
                    cout << a[i][j];
                }
                cout << "\n";
            }
            cout << "--------------------\n";
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=10; j++){
            cout << a[i][j];
        }
        cout << "\n";
    }
}
