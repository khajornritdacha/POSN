#include<bits/stdc++.h>
using namespace std;
int n,cnt;
long long OG,temp,con=1;
deque<char> deq;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        char x;
        cin >> x;
        deq.emplace_back(x);
        OG = OG*31+x;
        con*=31;
    }
    temp = OG;
    for(cnt=1;cnt<=n;cnt++){
        char x = deq.front();
        deq.pop_front();
        temp = temp*31+x;
        temp-=con*x;
        deq.emplace_back(x);
        if(temp==OG){
            cout << cnt;
            return 0;
        }
    }
    cout << n;
}
