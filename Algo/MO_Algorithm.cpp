///Mo's algorithm for solving a number of range queries
///https://www.spoj.com/problems/DQUERY/
///sort query by l/(block size) then by r
///Then, just moving pointer and call remove and add EZEZ
///Time Complexity O( (N+Q)*sqrt(N)*F ) when N is the number of elements in array, Q is the number of Queries, and F is time complexity for add() and rem() function.

#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 1e6+10;
using ll = long long;
using pi = pair<int,int>;

int n,a[N],ans[N],fre[N],BS,cnt,Q;


struct DATA{
    int l,r,idx;
    bool operator<(DATA other)const{
        if(l/BS != other.l/BS)
            return l < other.l;
        return r < other.r;
    }
};

void rem(int idx){
    if(--fre[a[idx]] == 0) cnt--;
    return;
}

void add(int idx){
    if(++fre[a[idx]] == 1) cnt++;
    return;
}

int getans(){
    return cnt;
}

vector<DATA> qq;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    BS = (int) sqrt(n+.0) + 1;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> Q;
    for(int i=1; i<=Q; i++){
        DATA tmp;
        cin >> tmp.l >> tmp.r;
        tmp.idx = i;
        qq.push_back(tmp);
    }
    sort(qq.begin(), qq.end());

    int nl = 0, nr = 0;
    for(DATA &now : qq){

        while(nl < now.l){
            rem(nl);
            nl++;
        }
        while(nl > now.l){
            nl--;
            add(nl);
        }
        while(nr < now.r){
            nr++;
            add(nr);
        }
        while(nr > now.r){
            rem(nr);
            nr--;
        }

        ans[now.idx] = getans();
    }

    for(int i=1; i<=Q; i++){
        cout << ans[i] << "\n";
    }
}
