#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+10;
using pi = pair<int,int>;

///https://www.spoj.com/problems/EXPEDI/

int n,P,ans;
pi a[N];
priority_queue<int> pq;

void test_case(){
    ans = 0;
    bool ok = true;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    cin >> a[n+1].first >> P;

    //for(int i = 0; i <= n+1; i++) cout << a[i] << " \n"[i==n+1];
    //cout << P << "\n";

    sort(a+1, a+n+1);

    for(int i = n; i >= 0; i--){
        //cout << P << "\n";
        while(!pq.empty() and a[i+1].first-a[i].first > P){
            //cout << pq.top() << "\n";
            ans++;
            P += pq.top();
            pq.pop();
        }
        if(a[i+1].first-a[i].first > P){ ok = false; break; }
        P -= a[i+1].first-a[i].first;
        pq.push(a[i].second);
    }

    if(!ok) ans = -1;
    cout << ans << "\n";

    memset(a, 0, sizeof(a));
    while(!pq.empty()) pq.pop();
    return;
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}
