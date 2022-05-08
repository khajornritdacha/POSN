#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5+10;
int n,a[N],hp;
priority_queue<int, vector<int>, greater<int>> pq;
///https://codeforces.com/contest/1526/problem/C2

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    for(int i=1; i<=n; i++){
        if(-a[i] <= hp){
            pq.emplace(a[i]);
            hp += a[i];
        }else if(!pq.empty() and a[i] > pq.top() and hp-pq.top()+a[i]>=0){
            hp -= pq.top();
            pq.pop();
            pq.emplace(a[i]);
            hp += a[i];
        }
    }
    cout << pq.size();
}
