#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n,a[N],pos[N];

int main(void){
    int ans = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 2; i <= n; i++){
        if(pos[i] < pos[i-1]){
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
