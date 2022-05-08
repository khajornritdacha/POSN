#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

using tu = tuple<int,int,int>;
const int N = 1e5+10;
int n,K,a[N],dp[N];
deque<tu> dq;
multiset<int> ss;
///Divide array into interval that max values changes
///dq = (max value of that interval, size of interval, leftmost element)
///ss = dp(leftmost-1 + maxval)
///dp(i) = first element of multiset
///Dont forget to maintain dq to contain atmost K elements to the left
///Cr: P'Top
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> K;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i] = 1e9;
    }

    for(int i=1; i<=n; i++){

        if(i > K and !dq.empty()){
            auto &[x,y,z] = dq.front();
            ss.erase(ss.find(dp[z-1]+x));
            --y, ++z;
            if(y == 0)
                dq.pop_front();
            else
                ss.insert(dp[z-1]+x);
        }

        if(DEBUG){
            deque<tu> tmp = dq;
            cout << "NOW : " << i << "\n";
            cout << "DQ :\n";
            for(auto [x,y,z] : tmp){
                cout << x << " " << y << " " << z << "\n";
            }
            cout << "SET: ";
            for(int s : ss)
                cout << s << " ";
            cout << "\n\n";
        }

        int sz = 1, last = i;
        while(!dq.empty() and a[i] >= get<0>(dq.back())){
            auto &[x,y,z] = dq.back();

            if(DEBUG){
                cout << a[i] << " > " << x << " " << y << " " << z << "\n";
            }

            last = z;
            sz += y;
            ss.erase(ss.find(dp[z-1]+x));
            dq.pop_back();
        }
        dq.emplace_back(a[i], sz, last);
        ss.insert(dp[last-1]+a[i]);

        if(DEBUG){
            deque<tu> tmp = dq;
            cout << "DQ :\n";
            for(auto [x,y,z] : tmp){
                cout << x << " " << y << " " << z << "\n";
            }
            cout << "SET: ";
            for(int s : ss)
                cout << s << " ";
            cout << "\n\n";
        }

        dp[i] = *ss.begin();
    }
    cout << dp[n];
}
