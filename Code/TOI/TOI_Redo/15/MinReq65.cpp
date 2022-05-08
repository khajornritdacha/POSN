#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;
using ll = long long;
using pi = pair<int,int>;
using tu = tuple<int,int,int>;

int n,m,TC;
int L[15],A[15],S[N],T[15],qs[N],Q[15];
pair<int,int> order[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> TC;

    for(int i = 1; i <= n; i++){
        cin >> L[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    sort(L+1, L+n+1); sort(A+1, A+n+1);

    for(int i = 1; i <= n; i++){
        L[i] -= A[i];
    }

    for(int i = 1; i <= m; i++){
        cin >> S[i];
        qs[i] = qs[i-1]+S[i];
    }

    for(int t = 1; t <= TC; t++){
        cin >> T[t];
    }

    for(int t = 1; t <= TC; t++){
        for(int i = 1; i <= n; i++){
            cin >> Q[i];
        }
        for(int i = 2; i <= n; i++){
            order[i-1] = {qs[Q[i]-1]-qs[Q[i-1]-1], i-1};
        }
        order[n] = {qs[m]-qs[Q[n]-1], n};

        sort(order+1, order+n+1);

        bool ok = true;
        for(int i = 1; i <= n; i++){
            ll now = 0, ti = 1;
            for(int j = Q[order[i].second], lim = Q[order[i].second+1]-1; j <= lim; j++){
                if(ti > T[t] or S[j] > L[i]){
                    ok = false;
                    break;
                }
                if(now+S[j] > L[i]){
                    ti++;
                    now = 0;
                }
                now += S[j];
            }
            if(!ok) break;
        }

        if(ok){
            cout << "P\n";
        }else{
            cout << "F\n";
        }

    }

    return 0;
}
