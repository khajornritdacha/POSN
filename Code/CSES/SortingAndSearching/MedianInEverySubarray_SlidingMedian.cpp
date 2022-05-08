#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 2e5+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;
using ll = long long;

int n,K,a[N];

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    multiset<int> le, ri;
    int lsz = (K+1)/2, rsz = K-lsz;
    for(int i = 1; i <= n; i++){
        if(le.empty() or a[i] <= *(le.rbegin()))
            le.insert(a[i]);
        else
            ri.insert(a[i]);
        
        if(i >= K+1){ //erase a[i-K]
            if(a[i-K] <= *(le.rbegin())){
                le.erase(le.find(a[i-K]));
            } else {
                ri.erase(ri.find(a[i-K]));
            }
        }
        
        while(le.size() > lsz){
            int k = *(le.rbegin());
            le.erase(le.find(k));
            ri.insert(k);
        }
        while(ri.size() > rsz){
            int k = *(ri.begin());
            ri.erase(ri.find(k));
            le.insert(k);
        }

        if(i >= K){   
            cout << *(le.rbegin()) << " ";
        }
    }
    return 0;
}