#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 25;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;
///http://www.usaco.org/index.php?page=viewproblem2&cpid=740
void setIO(string name=""){
    ios_base::sync_with_stdio(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

vector<pi> use[N*N];
queue<pi> qq;
vector<tuple<int,int,int,int>> al[N][N];
char a[N][N];
int n,pr[]={-1,1,0,0},pc[]={0,0,-1,1},chr[30],vi[N][N],cou,ans;
bool ok[N][N];

main(){
    setIO("where");
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }

    for(int i=1; i<=n*n; i++){
        for(int j=1; j<=(i/2) and j<=n; j++){
            if(i%j == 0 and i/j <= n){
                use[i].emplace_back(j, i/j);
                use[i].emplace_back(i/j, j);
            }
        }
    }

    /*if(DEBUG){
        for(int i=n*n; i>=1; i--){
            cout << "USE " << i << "\n";
            for(auto [x, y] : use[i]){
                cout << x << " " << y << "\n";
            }
            cout << "\n";
        }
    }*/

    for(int sz = n*n; sz>=1; sz--){
        for(auto [szr, szc] : use[sz]){
            for(int i=1; i<=n-szr+1; i++){
                for(int j=1; j<=n-szc+1; j++){
                    int vl = j, vr = j+szc-1, hu = i, hd = i+szr-1;

                    bool duu = false;
                    for(auto [r1, c1, r2, c2] : al[i][j]){
                        if(hu >= r1 and hd <= r2 and vl >= c1 and vr <= c2){
                            duu = true;
                        }
                    }
                    if(duu) continue;

                    cou++;
                    for(int str=hu; str<=hd; str++){
                        for(int stc=vl; stc<=vr; stc++){
                            if(vi[str][stc] != cou){

                                ++chr[a[str][stc]-'A'];

                                qq.emplace(str, stc);
                                while(!qq.empty()){
                                    auto [nr, nc] = qq.front();
                                    qq.pop();
                                    vi[nr][nc] = cou;
                                    for(int k=0; k<4; k++){
                                        int gr = nr+pr[k], gc = nc+pc[k];
                                        if(gr < hu or gr > hd or gc < vl or gc > vr) continue;
                                        if(vi[gr][gc] != cou and a[gr][gc] == a[nr][nc]){
                                            qq.emplace(gr, gc);
                                            vi[gr][gc] = cou;
                                        }
                                    }
                                }
                            }

                        }
                    }

                    int one = 0, two = 0;
                    for(int k=0; k<26; k++){
                        if(chr[k] == 1)
                            one++;
                        if(chr[k] > 1)
                            two++;
                    }
                    if(one == 1 and two == 1){
                        for(int str=hu; str<=hd; str++){
                            for(int stc=vl; stc<=vr; stc++){
                                ok[str][stc] = true;
                                al[str][stc].emplace_back(hu, vl, hd, vr);
                            }
                        }
                        ans++;

                        if(DEBUG){
                            printf("-------------------------\n");
                            printf("START : %d %d\n", i, j);
                            printf("SZ : %d %d\n", szr, szc);
                            for(int k=0; k<26; k++){
                                printf("%c : %d\n", k+'A', chr[k]);
                            }
                            printf("-------------------------\n");
                        }
                    }
                    memset(chr, 0, sizeof(chr));
                }
            }
        }
    }

    cout << ans << "\n";
}

