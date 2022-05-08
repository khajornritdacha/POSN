#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
int n,pr[N],pc[N],mx[N],Q,szr[N],szc[N];
///pr for real group
///pc for group consecutive node together to optimize time for type 2 question
///if type 2 question were asked -> group both real and consecutive
///union with rank takes more time than without rank
///https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/C
int fir(int x){
    if(pr[x] == x)
        return pr[x];
    return pr[x] = fir(pr[x]);
}

int fic(int x){
    if(pc[x] == x)
        return pc[x];
    return pc[x] = fic(pc[x]);
}

void unir(int u, int v){
    int hu = fir(u), hv = fir(v);
    if(hu != hv){
        if(szr[hu] < szr[hv])
            swap(hu, hv);
        pr[hv] = hu;
        szr[hu] += szr[hv];
    }
}

void unic(int u, int v){
    int hu = fic(u), hv = fic(v);
    int hru = fir(u), hrv = fir(v);
    if(hru != hrv or hu != hv){
        unir(u, v);
        if(szc[hu] < szc[hv])
            swap(hu, hv);
        szc[hu] += szc[hv];
        pc[hv] = hu;
        mx[hu] = max(mx[hu], mx[hv]);
    }
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=1; i<=n; i++){
        pr[i] = pc[i] = mx[i] = i;
        szr[i] = szc[i] = 1;
    }
    while(Q--){
        int code,u,v;
        cin >> code >> u >> v;
        if(code == 1){
            unir(u,v);
        }else if(code == 2){
            int x = mx[fic(u)];
            while(x+1 <= v){
                unic(x, x+1);
                x = mx[fic(x)];
            }
        }else if(code == 3){
            cout << ((fir(u) == fir(v)) ? "YES" : "NO") << "\n";
        }
    }
}
