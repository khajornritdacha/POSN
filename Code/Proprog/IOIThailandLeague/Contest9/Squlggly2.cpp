#include<bits/stdc++.h>
using namespace std;

///0 -> l h l h l ...
///1 -> h l h l h ...
const int N = 1e6+10;
int n;
long long a[N],b[N][2],ans[2];

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        b[i][0] = b[i][1] = a[i];
    }
    for(int i=2; i<=n; i++){
        if(i%2 == 0){
            b[i][0] = max(b[i-1][0]+1, a[i]);
            b[i][1] = min(b[i-1][1]-1, a[i]);
        }else{
            b[i][0] = min(b[i-1][0]-1, a[i]);
            b[i][1] = max(b[i-1][1]+1, a[i]);
        }
        ans[0] += abs(a[i]-b[i][0]);
        ans[1] += abs(a[i]-b[i][1]);
    }

    cout << min(ans[0], ans[1]);
}
