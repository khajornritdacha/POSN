#include<bits/stdc++.h>
using namespace std;

int n,Q,a[1010];

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> Q;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    while(Q--){
        int st,ra;
        cin >> st >> ra;
        st--;
        vector<int> vec;
        for(int i=st; i<min(n,st+ra); i++){
            vec.emplace_back(a[i]);
        }
        if(st+ra-1 >= n){
            int lim = (st+ra-1)%n;
            for(int i=0; i<=lim; i++){
                vec.emplace_back(a[i]);
            }
        }

        reverse(vec.begin(), vec.end());
        int j=0;
        for(int i=st; i<min(n,st+ra); i++){
            a[i] = vec[j++];
        }
        if(st+ra-1 >= n){
            int lim = (st+ra-1)%n;
            for(int i=0; i<=lim; i++){
                a[i] = vec[j++];
            }
        }

        /*for(int i=0; i<n; i++){
            cout << a[i] << " \n"[i==n-1];
        }*/

    }

    for(int i=0; i<n; i++){
        cout << a[i] << " \n"[i==n-1];
    }
}
