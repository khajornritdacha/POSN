#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],l,n,last[1005],pre,cnt;
main(){
    for(int i=0; i<1002; i++) last[i]=1;
    cin >> l >> n;
    int i=0;
    while(true){
        int j=2,k;
        cnt++;
        for(k=last[1]; k<last[1]+l; k++){
            i++;
            a[k][j]=i;
            if(i>=n){
                cout << cnt;
                return 0;
            }
        }
        last[1]+=l;
        pre=last[1]-1;
        while(true){
            if(pre-1==0){
                break;
            }
            for(k=last[j]; k<pre; k++){
                i++;
                a[k][j]=i;
                //cout << a[k][j] << " ";
                if(i>=n){
                    cout << cnt;
                    return 0;
                }
            }
            pre--;
            last[j]=k;
            j++;
        }
        /*for(int k=0; k<20; k++){
            for(int j=0; j<20; j++){
                cout << a[k][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";*/
    }
    //cout << cnt;
}
