#include<bits/stdc++.h>
using namespace std;

map<vector<int>, int> mp;
string A,B;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> A >> B;
    if(A.size() > B.size())
        swap(A,B);
    int n = A.size();
    int m = B.size();
    for(int sz = n; sz>=1; sz--){
        mp.clear();
        vector<int> cnt(26, 0);
        for(int i=0; i<m; i++){
            cnt[B[i]-'A']++;
            if(i >= sz)
                cnt[B[i-sz]-'A']--;
            if(i >= sz-1)
                mp[cnt] = sz;
        }
        cnt.clear();
        cnt.resize(26, 0);
        for(int i=0; i<n; i++){
            cnt[A[i]-'A']++;
            if(i >= sz)
                cnt[A[i-sz]-'A']--;
            if(i >= sz-1 and mp.find(cnt) != mp.end()){
                cout << sz;
                return 0;
            }
        }
    }
    cout << 0;
}
