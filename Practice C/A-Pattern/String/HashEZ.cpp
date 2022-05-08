#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
int M = 1e9+7, b = 31;
int tex_h[1000010],pat_h[1000010],pw[1000010];
char text[1000010],pat[1000010];
int get_hsh(int l, int r){
    if(l-1 < 0) return tex_h[r]%M;
    return (tex_h[r]-(tex_h[l-1]*pw[r-l+1])%M+M)%M;
}
/// No need to calculate modular inverse.
main(){
    cin >> text+1 >> pat+1;
    int n = strlen(text+1);
    int m = strlen(pat+1);
    for(int i=1; i<=m; i++){
        pat_h[i] = ((pat_h[i-1]*b)%M+pat[i])%M;
        //cout << pat_h[i] << " \n"[i==m];
    }
    pw[0] = 1;
    for(int i=1; i<=n; i++){
        tex_h[i] = ((tex_h[i-1]*b)%M+text[i])%M;
        pw[i] = (pw[i-1]*b)%M;
        //cout << tex_h[i] << " \n"[i==n];
    }
    for(int i=1; i<=n; i++){
        //cout << get_hsh(i-m+1,i) << " \n"[i==n];
        if(get_hsh(i-m+1,i) == pat_h[m]){
            cout << "Found at :" << i << "\n";
        }
    }

}
