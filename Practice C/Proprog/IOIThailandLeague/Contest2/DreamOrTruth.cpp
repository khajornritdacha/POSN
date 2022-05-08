#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
string a,b,pat;
vector<int> c,d;
int tot[N];
main(){
    cin >> a >> b >> pat;
    int n = a.size();
    int m = b.size();
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end()); reverse(pat.begin(), pat.end());
    if(n < m){
        swap(a,b);
        swap(n,m);
    }
    for(int i=0; i<n; i++){
        c.push_back(a[i]-'0');
    }
    for(int i=0; i<m; i++){
        d.push_back(b[i]-'0');
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            tot[j+i] += d[i]*c[j];
        }
        for(int j=0; j<=n+m+5; j++){
            tot[j+1] += tot[j]/10;
            tot[j] %= 10;
        }
    }
    int sz;
    for(int i=n+m+5; i>=0; i--){
        if(tot[i] != 0){
            sz = i;
            break;
        }
    }
    sz++;
    if(sz != pat.size()){
        cout << "dream";
    }else{
        for(int i=0; i<sz; i++){
            if(tot[i] != pat[i]-'0'){
                cout << "dream";
                return 0;
            }
        }
        cout << "truth";
    }
}
