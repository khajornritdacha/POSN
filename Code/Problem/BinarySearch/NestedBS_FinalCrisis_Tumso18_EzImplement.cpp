#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,Q;


int solve(const vector<int> &qsA, const vector<int> &qsB, int a, int c, int b, int d, int K){
    int ans = 2e9, l = 0, r = 2e9;
    while(l <= r){
        int mid = (l+r)>>1;
        int bio = upper_bound(qsA.begin(), qsA.end(), mid+qsA[a-1])-qsA.begin()-1;
        int his = upper_bound(qsB.begin(), qsB.end(), mid+qsB[b-1])-qsB.begin()-1;
        if(bio > c) bio = c;
        if(his > d) his = d;
        if(bio-a+1+his-b+1 >= K){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> Q;
    vector<int> A(n+1), B(m+1), qsA(n+1), qsB(m+1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
        qsA[i] = qsA[i-1]+A[i];
        //cout << qsA[i] << " \n"[i==n];
    }
    for(int i = 1; i <= m; i++){
        cin >> B[i];
        qsB[i] = qsB[i-1]+B[i];
        //cout << qsB[i] << " \n"[i==m];
    }
    while(Q--){
        int a,b,c,d,K; cin >> a >> b >> c >> d >> K;
        cout << solve(qsA, qsB, a, c, b, d, K) << "\n";
    }

    return 0;
}
