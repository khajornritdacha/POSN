#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int arr[N], n, Q;
long long fen[N];

//For range [a, b], it contains every value in range [a, b] if and only if its sum of elements is equal to sum of index

void up(int idx, int val){
    if(idx <= 0) return;
    for(; idx < N; idx += idx&-idx) fen[idx] += val;
}

long long sum(int idx){
    long long res = 0;
    for(; idx; idx -= idx&-idx) res += fen[idx];
    return res;
}

long long ask(int l, int r){
    return sum(r)-sum(l-1);
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) arr[i] = i, up(i, i);

    while(Q--){
        int cd, a, b; cin >> cd >> a >> b;
        a++, b++;
        if(cd == 0){
            up(a, arr[b]-arr[a]);
            up(b, arr[a]-arr[b]);
            swap(arr[a], arr[b]);
        } else if(cd == 1){
            long long res = ask(a, b);
            // cout << res << " " << 1ll*(a+b)*(b-a+1)/2 << "\n";
            if(res == 1ll*(a+b)*(b-a+1)/2){
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}