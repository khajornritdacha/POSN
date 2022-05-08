#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
int n,a[N],ans;

main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    int lf = 1, ri = n;
    for(int i=1; i<=n; i++){
        int ac = (i%2 ? lf : ri);

        if(i%2)
            lf++;
        else
            ri--;

        if(a[ac] == ac){
            ans++;
            continue;
        }

        int pos;
        for(int i=1; i<=n; i++){
            if(a[i] == ac){
                pos = i;
                break;
            }
        }

        if(pos > ac){
            for(int i=pos; i>ac; i--){
                a[i] = a[i-1];
            }
        }else{
            for(int i=pos; i<ac; i++){
                a[i] = a[i+1];
            }
        }
        a[ac] = ac;

        /*for(int i=1; i<=n; i++){
            cout << a[i] << " \n"[i==n];
        }*/
    }

    cout << ans;
}
