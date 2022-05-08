#include<bits/stdc++.h>
using namespace std;
int n,R,C,pr[]={0,0,1,-1,1,1,-1,-1}, pc[]={1,-1,0,0,1,-1,-1,1};
char s[30],a[30][30];
bool ok;
bool chk(int r, int c){
    return (r>=1 and r<=R and c>=1 and C<=C);
}
void solve(int i, int j, int k){
    int cnt = 0;
    for(int l=0; l<n; l++){
        int gor = i+l*pr[k], goc = j+l*pc[k];
        if(chk(gor, goc) and a[gor][goc] == s[l])
            cnt++;
    }
    if(cnt == n)
        ok=true;
}
char low(char x){
    if('A' <= x and x <= 'Z')
        return x+'a'-'A';
    return x;
}
main(){
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> a[i][j];
            a[i][j] = low(a[i][j]);
        }
    }
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        n = strlen(s);
        ok = false;
        for(int i=0; i<n; i++)
            s[i] = low(s[i]);
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                for(int k=0; k<8; k++){
                    solve(i, j, k);
                    if(ok){
                        cout << i-1 << " " << j-1 << "\n";
                        ///In proprog dont need -1 but in Programming do require -1
                        break;
                    }
                }
                if(ok) break;
            }
            if(ok) break;
        }
    }
}
