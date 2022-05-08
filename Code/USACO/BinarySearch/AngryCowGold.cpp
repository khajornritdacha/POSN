#include<bits/stdc++.h>
#define DEBUG false
#define int long long
using namespace std;

const int N = 5e4+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;

///http://www.usaco.org/index.php?page=viewproblem2&cpid=597
lb a[N],ep=0.0000001;
int n;

void setIO(string name=""){
    ios_base::sync_with_stdio(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int chk2(lb st, lb R){
    int fl = -1, fr;
    for(int i=1; i<=n; i++){
        if(st-a[i] <= R and fl == -1)
            fl = i;
        if(a[i]-st <= R)
            fr = i;
    }

    if(DEBUG){
        printf("FL FR : %d %d\n", fl, fr);
    }

    lb nr = R-1;
    int ni = fl, nj = fl-1;
    while(nj >= 1){
        while(nj >= 1 and a[ni]-a[nj] <= nr)
            nj--;
        ni = nj+1, nr--;
        if(nr <= 0 or (nj >= 1 and a[ni]-a[nj] > nr))
            break;
    }
    if(nj >= 1) return 1;

    nr = R-1;
    ni = fr, nj = fr+1;
    while(nj <= n){
        while(nj <= n and a[nj]-a[ni] <= nr)
            nj++;
        ni = nj-1, nr--;
        if(nr <= 0 or (nj <= n and a[nj]-a[ni] > nr))
            break;
    }
    if(nj <= n) return -1;
    return 0;
}

bool chk(lb R){
    lb l = a[1], r = a[n], mid;
    while(r-l > ep){
        mid = (l+r)/2;
        int tmp = chk2(mid, R);

        if(DEBUG){
            printf("mid : %Lf = %d\n", mid, tmp);
        }

        if(tmp == 0)
            return true;
        else if(tmp == -1)
            l = mid;
        else
            r = mid;
    }
    return false;
}
main(){
    setIO("angry");
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    /*for(int i=1; i<=n; i++){
        cout << a[i] << " \n"[i==n];
    }*/

    lb l = 1, r = 1e9, mid, ans;
    while(r-l > ep){
        mid = (l+r)/2;

        if(DEBUG){
            printf("-------------------------\n");
            printf("PrimeMID : %Lf\n", mid);
        }
        if(chk(mid)){
            ans = mid;
            r = mid;
        }else{
            l = mid;
        }

        if(DEBUG){
            printf("-------------------------\n");
        }
    }
    cout << setprecision(1) << fixed << ans << "\n";
}

