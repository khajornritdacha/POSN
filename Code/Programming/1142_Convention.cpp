///SegTree LazyPropagation
#include<bits/stdc++.h>
using namespace std;
int t[400010],n,q,h,d[200010],k,st[200010],ed[200010],v;
unordered_map<int,int> mp;
vector<int> vec;
void apply(int i, int val){
    t[i] += val;
    if(i < v)
        d[i] += val;
}
void build(int i){
    while(i > 1){
        i/=2;
        t[i] = max(t[i*2], t[i*2+1]) + d[i];
    }
}
void push(int i){
    for(int s = h; s; s--){
        int now = i >> s;
        if(d[now] != 0){
            apply(now*2, d[now]);
            apply(now*2+1, d[now]);
            d[now] = 0;
        }
    }
}
void up(int l, int r, int val){
    l += v-1, r+=v-1;
    int l0 = l, r0 = r;
    for(; l<=r; l/=2, r/=2){
        if(l%2){
            apply(l++, val);
        }
        if(r%2 == 0)
            apply(r--, val);
        }
    build(l0);
    build(r0);
}
int query(int l, int r){
    l +=v-1, r+=v-1;
    int mx = 0;
    push(l);
    push(r);
    for(; l<=r; l/=2,r/=2){
        if(l%2)
            mx = max(mx, t[l++]);
        if(r%2 == 0)
            mx = max(mx, t[r--]);
    }
    return mx;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> st[i] >> ed[i];
        vec.emplace_back(st[i]);
        vec.emplace_back(ed[i]);
    }
    sort(vec.begin(),vec.end());
    int pos = 1;
    mp[vec[0]] = pos++;
    for(int i=1; i<vec.size(); i++){
        if(vec[i]!=vec[i-1])
            mp[vec[i]] = pos++;
    }
    h = sizeof(int)*8-__builtin_clz((int)mp.size());
    v = mp.size();
    //cout << mp.size() << " " << h << "\n";
    for(int i=1; i<=n; i++){
        int l = mp[st[i]];
        int r = mp[ed[i]];
        //cout << l << " " << r << " " << query(l,r) << "\n";
        if(query(l, r) < k){
            cout << "yes\n";
            up(l, r, 1);
        }else{
            cout << "no\n";
        }
    }
}
