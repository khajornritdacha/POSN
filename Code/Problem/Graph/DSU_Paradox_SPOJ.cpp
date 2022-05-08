#include <bits/stdc++.h>
using namespace std;

const int N = 210, INF = 1e9;
using ll = long long;
using pi = pair<int,int>;

//i can't be in the same component as i+n
//https://www.spoj.com/problems/PARADOX/

int cp[N],n;

int fi(int x){ return cp[x] = (cp[x] == x) ? x : fi(cp[x]); }

void uni(int u, int v){
    u = fi(u), v = fi(v);
    if(u != v) 
        cp[v] = u;
    return;
}

void test_case(){
    cin >> n;
    if(n == 0) exit(0);

    for(int i = 1; i <= 2*n; i++) cp[i] = i;

    for(int i = 1; i <= n; i++){
        int v;
        string op;
        cin >> v >> op;
        if(op == "false"){
            uni(i, v+n); //i is true then v is false
            uni(i+n, v); //i is false then v is true
        } else {
            uni(i, v);
            uni(i+n, v+n);
        }
    }

    for(int i = 1; i <= n; i++) if(fi(i) == fi(i+n)){
        cout << "PARADOX\n";
        return;
    }
    cout << "NOT PARADOX\n";
    return;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(true){
        test_case();
    }

    return 0;
}