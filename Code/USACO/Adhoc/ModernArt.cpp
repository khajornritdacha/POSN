#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 15;
int n,a[N][N],mnr[N],mxr[N],mnc[N],mxc[N],ans;
char b[N][N];
bool chk[N];

void setIO(string name = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

main(){
    setIO("art");
    for(int i=1; i<=9; i++){
        mnr[i] = mnc[i] = 1e9;
        mxr[i] = mxc[i] = -1e9;
    }
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> b[i][j];
            a[i][j] = b[i][j]-'0';
            mnr[a[i][j]] = min(mnr[a[i][j]], i);
            mxr[a[i][j]] = max(mxr[a[i][j]], i);
            mnc[a[i][j]] = min(mnc[a[i][j]], j);
            mxc[a[i][j]] = max(mxc[a[i][j]], j);
            chk[a[i][j]] = true;
        }
    }

    if(DEBUG){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << a[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
        for(int i=1; i<=9; i++){
            cout << "I : " << i << " " << mnr[i] << " " << mnc[i] << " " << mxr[i] << " " << mxc[i] << "\n";
        }
    }

    for(int t=1; t<=9; t++){
        if(mnr[t] == 1e9) continue;
        for(int i=mnr[t]; i<=mxr[t]; i++){
            for(int j=mnc[t]; j<=mxc[t]; j++){
                if(a[i][j] != t)
                    chk[a[i][j]] = false;

                if(DEBUG){
                    cout << "T : " << t << " = ";
                    cout << i << " " << j << " " << a[i][j] << "\n";
                }
            }
        }
    }

    for(int t=1; t<=9; t++){
        //cout << chk[t] << " \n"[t==9];
        ans += chk[t];
    }

    cout << ans;
}
