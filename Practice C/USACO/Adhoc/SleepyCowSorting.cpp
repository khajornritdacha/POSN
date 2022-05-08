#include<bits/stdc++.h>
using namespace std;
int n,a[110],t;
main(){
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    while(true){
        bool sorted = true;
        for(int i=1; i<n; i++){
            if(a[i]>a[i+1]){
                sorted = false;
                break;
            }
        }
        if(sorted){
            break;
        }
        int now = a[1];
        for(int i=1; i<=n; i++){
            bool incre=true;
            int tmp = a[i];
            a[i] = now;
            for(int j=i+1; j<=n; j++){
                if(a[j] < a[j-1]){
                    incre =false;
                    break;
                }
            }
            a[i] = tmp;
            if(incre){
                for(int j=1; j<i; j++){
                    a[j]=a[j+1];
                }
                a[i]=now;
                break;
            }
        }
        for(int i=1; i<=n; i++){
            //cout << a[i] << " \n"[i==n];
        }
        t++;
    }
    cout << t;
}
