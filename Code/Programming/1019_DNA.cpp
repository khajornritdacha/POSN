#include<bits/stdc++.h>
using namespace std;
string a,b;
int ans,mx;
main(){
    cin >> a >> b;
    int n = a.size(), m=b.size();
    if(n < m){
        swap(a,b);
        swap(n,m);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int k = 0;
            while(i+k < n and j+k < m and a[i+k] == b[j+k])
                k++;
            if(k > mx){
                mx = k;
                ans = i;
            }
        }
    }
    for(int i=0; i<mx; i++)
        cout << a[ans+i];
}
