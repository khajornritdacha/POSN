#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int n,S,t[N],v[N];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> S;
    cout << "0\n";
    for(int i=1; i<=n; i++){
        cin >> t[i] >> v[i];
        /*if(i >= 2){
            int tmp = ((S+v[i-1]-1)/v[i-1]+t[i-1]);
            if(tmp < (S+v[i]-1)/v[i]+t[i]){
                cout << "0\n";
            }else{
                int tmp2 = (S)/(tmp-t[i]);
                cout << v[i]-tmp2 << "\n";
                v[i] = tmp2;
            }
        }*/
        if(i>= 2 and (double)t[i]+(double)S/v[i] < (double)t[i-1]+(double)S/v[i-1]){
            //cout << "Crash\n";
            double vt = (double)S/((double)S/v[i-1]+t[i-1]-t[i]);
            cout << v[i]-(int)vt << "\n";
            v[i] = vt;
            //cout << "NEW V : " << vt << "\n";
        }else if(i>=2){
            cout << "0\n";
        }
    }

    /*for(int i=1; i<=n; i++){
        cout << t[i] << " " << v[i] << "\n";
    }*/
}
/*
3 10
2 4
3 5
4 6
*/
