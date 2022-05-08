#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
typedef long long ll;

int arr[N], n;

ll cnt_inversion(int l, int r) {
    if(l == r) return 0;
    int mid = (l+r)>>1;
    ll res = cnt_inversion(l, mid) + cnt_inversion(mid+1, r);

    int tmp[r-l+1] = {}, i = l, j = mid+1, k = 0;
    while(i <= mid and j <= r) {
        if (arr[j] < arr[i]) {
            res += mid-i+1;
            tmp[k++] = arr[j];
            j++;
        } else {
            tmp[k++] = arr[i];
            i++;
        }
    }
    while (i <= mid) tmp[k++] = arr[i++];
    while (j <= r) tmp[k++] = arr[j++];
    
    for (int pt = 0, pa = l; pa <= r; pt++, pa++) {
        arr[pa] = tmp[pt];
    }
    return res;
}

int main(void) {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    cout << cnt_inversion(1, n) << "\n";

    return 0;
}