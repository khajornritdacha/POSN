#include <bits/stdc++.h>
using namespace std;

const int N = 2010;

int cnt[N], ty, n, arr[N];

void cal(int lv = 1){
    if(lv == n+1){
        cnt[ty]++;
        return;
    }

    if(++cnt[arr[lv]] == 1) ty++;
    cal(lv+1);
    
    if(--cnt[arr[lv]] == 0) ty--;
    cal(lv+1);
}

int main(void){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    cal();

    for(int i = 1; i <= n; i++){
        cout << cnt[i] << "\n";
    }

}