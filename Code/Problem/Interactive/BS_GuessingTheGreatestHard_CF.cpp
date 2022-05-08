#include<bits/stdc++.h>
using namespace std;
int n;
map<pair<int,int>,int> mp;
int ask(int l, int r){
    if(mp.find({l,r})!=mp.end())
        return mp[{l,r}];
    cout << "? " << l << " " << r << endl;
    int tmp;
    cin >> tmp;
    return mp[{l,r}] = tmp;
}
main(){
    cin >> n;
    int l=1,r=n,mid,smax;
    smax = ask(l,r);
    if(smax == 1 || ask(1,smax) != smax){
        l = smax, r = n;
        while(r - l > 1){
            mid = (l+r)/2;
            if(ask(smax, mid) != smax){
                l = mid;
            }else{
                r = mid;
            }
        }
        cout << "! " << r << endl;
    }else{
        l = 1, r = smax;
        while(r - l > 1){
            mid = (l+r)/2;
            if(ask(mid,smax) != smax){
                r = mid;
            }else{
                l = mid;
            }
        }
        cout << "! " << l << endl;
    }
    return 0;
}
///https://codeforces.com/contest/1486/problem/C2
