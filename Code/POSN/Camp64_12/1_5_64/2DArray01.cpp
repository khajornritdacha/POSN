#include<bits/stdc++.h>
using namespace std;

const int D = 35, N = 55;
int Day,n,ab[N],on[N],la[N],daycome[D],daylate[D],a[D][N];

main(){
    cin >> Day >> n;
    for(int i=1; i<=Day; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            if(a[i][j] == 0){
                ab[j]++;
            }else if(a[i][j] == 1){
                on[j]++;
                daycome[i]++;
            }else{
                daycome[i]++;
                daylate[i]++;
                if(++la[j] == 2){
                    la[j] = 0;
                    ab[j]++;
                }
            }
        }
    }

    ///absent
    int mxab = *max_element(ab+1, ab+n+1);
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(ab[i] == mxab){
            cout << i << " ";
            cnt++;
        }
    }
    if(cnt == 0){
        cout << 0;
    }
    cout << "\n";

    ///Come everyday without late
    cnt = 0;
    for(int i=1; i<=n; i++){
        if(on[i] == Day){
            cout << i << " ";
            cnt++;
        }
    }
    if(cnt == 0)
        cout << 0;
    cout << "\n";

    ///Fail
    cnt = 0;
    for(int i=1; i<=n; i++){
        if(ab[i] > (Day+3)/4){
            cout << i << " ";
            cnt++;
        }
    }
    if(cnt == 0)
        cout << 0;
    cout << "\n";

    ///Total day which everyone comes
    cnt = 0;
    for(int i=1; i<=Day; i++){
        if(daycome[i] == n){
            cnt++;
        }
    }
    cout << cnt << "\n";

    ///Total day without any late student
    cnt = 0;
    for(int i=1; i<=Day; i++){
        if(daylate[i] == 0){
            cnt++;
        }
    }
    cout << cnt << "\n";
}
