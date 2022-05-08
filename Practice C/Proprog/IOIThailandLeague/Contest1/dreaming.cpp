#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
vector<char> ans;
char a[500],b[500];
int tot[500];
void pus(int x, int y, int i){
    x-='0';
    y-='0';
    int last = tot[i];
    int tmp = x+y+last;
    int td = tmp/10;
    tmp%=10;
    ans.emplace_back(tmp+'0');
    tot[i+1] = td;
}
main(){
    cin >> a >> b;
    int n = strlen(a), m = strlen(b);
    if(n < m){
        swap(a,b);
        swap(n,m);
    }
    reverse(a, a+n);
    reverse(b, b+m);
    for(int i=0; i<m; i++){
        pus(a[i], b[i], i);
    }
    int i = m;
    while(tot[i] != 0 or a[i] != 0 or b[i] != 0){
        if(a[i] == 0)
            a[i] = '0';
        if(b[i] == 0)
            b[i] = '0';
        pus(a[i], b[i], i);
        i++;
    }
    for(int i=sz(ans)-1; i>=0; i--)
        cout << ans[i];
}
