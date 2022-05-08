#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
void ask(int l, int r){
    cout << "? " << l << " " << r << "\n";
    cout.flush();
    return;
}
main(){
    cin >> n;
    int l=1,r=n,mid;
    while(l<=r){
        int get,g2;
        mid = (l+r)/2;
        if(r-l+1 <= 2){
            if(l==r){
               cout << "! " << l << "\n";
            }else{
                ask(l,r);
                cin >> get;
                cout << "! ";
                if(get == l)
                    cout << r;
                else
                    cout << l;
                cout << "\n";
            }
            cout.flush();
            return 0;
        }
        ask(l,r);
        cin >> get;
        if(get >= mid){
            ask(mid, r);
            cin >> g2;
            if(get!=g2){
                r=mid-1;
            }else{
                l=mid;
            }
        }else{
            ask(l,mid);
            cin >> g2;
            if(get!=g2){
                l = mid+1;
            }else{
                r = mid;
            }
        }
    }
    cout << "! " << mid << "\n";
    cout.flush();
    return 0;
}
///https://codeforces.com/contest/1486/problem/C1
