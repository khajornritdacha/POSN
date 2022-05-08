#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 28;
using ll = long long;
using pi = pair<int, int>;
using lb = long double;

int n,ssr,ssc,tr[N][N],tc[N][N],toi[300],pw[15],pr[]={-1,1,0,0},pc[]={0,0,-1,1};
char a[N][N],in[N][3*N];
set<int> ans;
bool vi[N][N][19683];

bool chk(vector<int> &now){
    vector<char> str(9);
    for(int i=0; i<9; i++){
        if(now[i] == 1)
            str[i] = 'M';
        else if(now[i] == 2)
            str[i] = 'O';
    }
    for(int i=0; i<3; i++){
        if(str[i*3] == 'M' and str[i*3+1] == 'O' and str[i*3+2] == 'O')
            return true;
        if(str[i*3] == 'O' and str[i*3+1] == 'O' and str[i*3+2] == 'M')
            return true;
        if(str[i] == 'M' and str[i+3] == 'O' and str[i+6] == 'O')
            return true;
        if(str[i+6] == 'M' and str[i+3] == 'O' and str[i] == 'O')
            return true;
    }
    if(str[0] == 'M' and str[4] == 'O' and str[8] == 'O')
        return true;
    if(str[0] == 'O' and str[4] == 'O' and str[8] == 'M')
        return true;
    if(str[2] == 'M' and str[4] == 'O' and str[6] == 'O')
        return true;
    if(str[2] == 'O' and str[4] == 'O' and str[6] == 'M')
        return true;
    return false;
}

void dfs(int r, int c, vector<int> now){
    if(a[r][c] == 'M' or a[r][c] == 'O'){
        int pos = (tr[r][c]-1)*3+tc[r][c]-1;
        if(now[pos] == 0)
            now[pos] = toi[a[r][c]];
    }

    int num = 0;
    for(int i=0; i<9; i++)
        num += now[i]*pw[i];

    if(vi[r][c][num])
        return;

    vi[r][c][num] = true;
    if(chk(now)){
        ans.insert(num);
        return;
    }

    for(int i=0; i<4; i++){
        int gr = r+pr[i], gc = c+pc[i];
        if(gr < 1 or gr > n or gc < 1 or gc > n) continue;
        if(a[gr][gc] == '#') continue;
        dfs(gr, gc, now);
    }
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); //freopen("multimoo.in", "r", stdin); freopen("multimoo.out", "w", stdout);
    cin >> n;
    pw[0] = 1, toi['M'] = 1, toi['O'] = 2;
    for(int i=1; i<=9; i++)
        pw[i] = 3*pw[i-1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=3*n; j++){
            cin >> in[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int co = (j-1)*3+1;
            a[i][j] = in[i][co];
            if(a[i][j] == 'B'){
                ssr = i, ssc = j;
            }else if(a[i][j] == 'M' or a[i][j] == 'O'){
                tr[i][j] = in[i][co+1]-'0';
                tc[i][j] = in[i][co+2]-'0';
            }
        }
    }

    if(DEBUG){
        cout << "Input\n";
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << a[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }

    dfs(ssr, ssc, vector<int>(9, 0));

    cout << ans.size();
}
