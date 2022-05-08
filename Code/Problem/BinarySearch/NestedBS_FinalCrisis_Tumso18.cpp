#include <bits/stdc++.h>
using namespace std;

int n,m,Q;

///https://beta.programming.in.th/tasks/tumso18_crisis

int bi(int val, const vector<int> &qs, int a, int b){
    int ans = a-1, l = a-1, r = b;
    while(l <= r){
        int mid = (l+r)>>1;
        if(qs[mid]-qs[a-1] <= val){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return ans-a+1;
}

int solve(const vector<int> &qsA, const vector<int> &qsB, int l1, int r1, int b, int d, int K){
    int ans = 2e9, l = 1, r = r1-l1+1;
    //cout << "L1R1 : " << l1 << " " << r1 << "\n";
    while(l <= r){
        int mid = (l+r)>>1;
        //cout << mid << " " << qsA[l1+mid-1] << " " << qsA[l1-1] << " " << bi(qsA[l1+mid-1]-qsA[l1-1], qsB, b, d) << "\n";
        if(mid+bi(qsA[l1+mid-1]-qsA[l1-1], qsB, b, d) >= K){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return ans;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> Q;
    vector<int> A(n+5), B(m+5), qsA(n+5), qsB(m+5);
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
        int t1 = solve(qsA, qsB, a, c, b, d, K);
        int t2 = solve(qsB, qsA, b, d, a, c, K);
        //cout << t1 << " " << t2 << "\n";
        if(t1 != 2e9) t1 = qsA[t1+a-1]-qsA[a-1];
        if(t2 != 2e9) t2 = qsB[t2+b-1]-qsB[b-1];
        cout << min(t1, t2) << "\n";
    }

    return 0;
}
