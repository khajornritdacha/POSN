#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

const int N = 1e5+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

///https://beta.programming.in.th/tasks/tumso18_sneaky

int n,ans[N],mx;
ll qs[N],M;
map<ll, ll> mn_ans, mn_val;

///sum(l+1, r) > (r-l)*M/2
///qs[r]-qs[l] > (r-l)*M/2
///2*qs[r]-rM  > 2*qs[l]-lM

void test_case(){
    cin >> n >> M;
    for(int i = 1; i <= n; i++){
        cin >> qs[i];
        qs[i] += qs[i-1];
        //cout << qs[i] << " \n"[i==n];
    }
    mn_ans[0] = 0; ///(1, 2*60-100)
    mn_val[0] = 0; ///(2*60-100, 1)
    for(int i = 1; i <= n; i++){
        ll val = qs[i]*2-1ll*i*M;
        auto it = mn_val.lower_bound(val);
        if(it != mn_val.begin()){
            it--;
            ans[i] = (it->second)+1;
            //cout << "I " << i << " = " << it->first << " " << it->second << "\n";
            if(ans[i] > mx){
                mn_val[val] = ans[i];
                mn_ans[ans[i]] = val;
                mx = ans[i];
            }else if(mn_ans[ans[i]] > val){
                mn_val.erase(mn_ans[ans[i]]);
                mn_ans[ans[i]] = val;
                mn_val[val] = ans[i];

            }
        }
        if(DEBUG){
            cout << "-----------\n";
            for(auto [x, y] : mn_ans){
                cout << x << " " << y << "\n";
            }
            cout << "\n\n";
            for(auto [x, y] : mn_val){
                cout << x << " " << y << "\n";
            }
            cout << "-----------\n";
        }
    }
    cout << ans[n] << "\n";
    return;
}
int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}

/*
3 10
6 7 3
*/
