#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2010;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

struct DATA{
    int l,r;
    char ld,rd;
};

int R,C,mn[N][2*N];
DATA a[N],wa[N][2*N];

 main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C;
    for(int i = R; i >= 1; i--){
        cin >> a[i].l >> a[i].ld >> a[i].r >> a[i].rd;
    }

    for(int i = 1; i <= R; i++){
        wa[i][0] = a[i];
        for(int j = 0; j < 2*C-1; j++){

            if(wa[i][j].l+1 == wa[i][j].r and wa[i][j].ld == 'R' and wa[i][j].rd == 'L'){ ///Case 1
                wa[i][j+1].l = wa[i][j].l;
                wa[i][j+1].ld =  'L';
                wa[i][j+1].r =  wa[i][j].r;
                wa[i][j+1].rd = 'R';
            }else if(wa[i][j].l == wa[i][j].r and wa[i][j].ld == 'R' and wa[i][j].rd == 'L'){ ///Case 2
                wa[i][j+1].l = wa[i][j].l-1;
                wa[i][j+1].ld = 'L';
                wa[i][j+1].r = wa[i][j].r+1;
                wa[i][j+1].rd = 'R';
            }else{
                int nl = wa[i][j].l-1;
                char ndl = wa[i][j].ld;
                if(wa[i][j].ld == 'R') nl = wa[i][j].l+1;
                if(wa[i][j].l == 0){
                    nl = 1;
                    ndl = 'R';
                }
                int nr = wa[i][j].r+1;
                char ndr = wa[i][j].rd;
                if(wa[i][j].rd == 'L') nr = wa[i][j].r-1;
                if(wa[i][j].r == C){
                    nr = C-1;
                    ndr = 'L';
                }
                wa[i][j+1].l = nl;
                wa[i][j+1].ld = ndl;
                wa[i][j+1].r = nr;
                wa[i][j+1].rd = ndr;
            }
        }
    }

    if(DEBUG){
        cout << "-------------\n";
        cout << "Check Stimulation\n";
        for(int j = 0; j < 2*C; j++){
            cout << wa[1][j].l << " " << wa[1][j].ld << " " << wa[1][j].r << " " << wa[1][j].rd << "\n";
        }
        cout << "-------------\n";
    }

    for(int t = 0; t < 2*C; t++){
        wa[R+1][t].l = -1;
        wa[R+1][t].ld = 'A';
        wa[R+1][t].r = C+1;
        wa[R+1][t].rd = 'B';
    }

    int ans = 1e9;
    for(int c = 0; c <= C; c++){

        for(int r = R+1; r >= 1; r--){
            for(int t = 0; t < 2*C; t++){
                mn[r][t] = 1e9;
            }
        }
        mn[R+1][0] = 0;
        //cout << "MN : " << mn[R+1][0] << "\n";
        for(int r = R+1; r > 1; r--){
            for(int cur_t = 0; cur_t < 2*C; cur_t++){
                if(mn[r][cur_t] == 1e9) continue;
                int pt = 1;
                bool ok = true;
                for(int t2 = cur_t+1; t2 < 2*C; t2++){
                    if(!ok) break;

                    if(DEBUG and c == 3){
                        cout << r << " " << c << " " << cur_t << " " << pt << " " << t2 << "\n";
                        cout << mn[r][t2] << " " << mn[r-1][t2] << "\n";
                        cout << wa[r][t2].l << " " << wa[r][t2].r << " " << wa[r-1][t2].l << " " << wa[r-1][t2].r << "\n";
                    }

                    if(wa[r][t2].l <= c and c <= wa[r][t2].r){ ///check if it's ok
                        if(wa[r-1][t2].l < c and c < wa[r-1][t2].r){
                            mn[r-1][t2] = min(mn[r-1][t2], mn[r][cur_t]+pt);
                        }
                    }else{
                        ok = false;
                        break;
                    }
                    pt++;
                }
                for(int t2 = 0; t2 <= cur_t; t2++){
                    if(!ok) break;
                    if(wa[r][t2].l <= c and c <= wa[r][t2].r){ ///check if it's ok
                        if(wa[r-1][t2].l < c and c < wa[r-1][t2].r){
                            mn[r-1][t2] = min(mn[r-1][t2], mn[r][cur_t]+pt);
                        }
                    }else{
                        ok = false;
                        break;
                    }
                    pt++;
                }

            }
        }
        for(int t = 0; t < 2*C; t++){
            ans = min(ans, mn[1][t]+1);
        }

        if(DEBUG and c == 3){
            for(int r = R+1; r >= 1; r--){
                cout << "R " << r << " : ";
                for(int t = 0; t < 2*C; t++){
                    cout << mn[r][t] << " ";
                }
                cout << "\n";
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
