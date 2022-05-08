#include<bits/stdc++.h>
#define DEBUG true
#define int long long
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;
using lb = long double;

vector<pair<lb, lb>> vec;
lb a[N],v[N],ep=0.0000000001;
int n;
///https://codeforces.com/contest/782/problem/B
int chk2(lb st, lb T){
    for(auto [pos, ve] : vec){
        if(abs(st-pos)/ve > T){
            //cout << abs(st-pos) << " " << abs(st-pos)/ve << " " << pos << " " << st << " " << T << "\n";
            if(st-pos > ep)
                return -1;
            return 1;
        }
    }
    return 0;
}

bool chk(lb T){
    lb l = vec.front().first, r = vec.back().first, mid, ans;
    while(r-l > ep){
        mid = (l+r)/2;
        int tmp = chk2(mid, T);
        //printf("T : %Lf, mid = %Lf ", T, mid);
        if(tmp == 0){
            //printf("0");
            return true;
        }else if(tmp == -1){
            //printf("-1");
            r = mid;
        }else{
            //printf("+1");
            l = mid;
        }
        //printf("\n");
    }
    return false;
}

void test_case(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        cin >> v[i];
        vec.emplace_back(a[i], v[i]);
    }
    sort(vec.begin(), vec.end());
    lb l = 0, r = 1e9, mid, ans;
    while(r-l > ep){
        mid = (l+r)/2;
        //printf("NOW : %Lf\n", mid);
        if(chk(mid)){
            //printf("Congrats!!!\n");
            ans = mid;
            r = mid;
        }else{
            l = mid;
        }
    }
    cout << setprecision(10) << fixed << ans << "\n";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=1;
   // cin >> t;
    while(t--){
        test_case();
    }
}
