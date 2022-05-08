#include <bits/stdc++.h>
#define int long long
#define DEBUG 0
using namespace std;

const int N = 2e5+10;
using tu = tuple<int,int,int>;
using pi = pair<int,int>;
using ll = long long;

int n,K,a[N];
multiset<int> le, ri;
ll suml,sumr,lsz,rsz;

//maintain 2 multiset : le for first (K+1)/2 least elements in range [i-K+1, i], ri for the latter
//minimum cost always exist at median

void add(int val){
    if(le.empty() or val <= *(le.rbegin())){
        le.insert(val);
        suml += val;
    } else {
        ri.insert(val);
        sumr += val;
    }
}

void del(int val){
    if(val <= *(le.rbegin())){ 
        le.erase(le.find(val));
        suml -= val;
    } else {
        ri.erase(ri.find(val));
        sumr -= val;
    }
}

void balance(){
    while(le.size() > lsz){
        int k = *(le.rbegin());
        suml -= k;
        sumr += k;
        le.erase(le.find(k));
        ri.insert(k);
    }
    while(ri.size() > rsz){
        int k = *(ri.begin());
        sumr -= k;
        suml += k;
        ri.erase(ri.find(k));
        le.insert(k);
    }
}

main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    lsz = (K+1)/2, rsz = K-lsz;
    for(int i = 1; i <= n; i++){
        add(a[i]);

        if(i >= K+1){
            del(a[i-K]);
        }

        balance();

        if(i >= K){
            ll me = *(le.rbegin());
            //cout << "I : " << i << " = " << me << "\n";
            cout << sumr - rsz*me + lsz*me - suml << " ";
        }
    }
    return 0;
}