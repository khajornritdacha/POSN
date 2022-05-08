#include<bits/stdc++.h>
using namespace std;
int n;
long long pw[25];
map<long long, int> ump;
main(){
    cin >> n;
    pw[0] = 1;
    for(int i=1; i<=19; i++){
        pw[i] = pw[i-1]*3;
    }
    for(int bit=0; bit<(1<<20); bit++){
        long long sum = 0, cnt = 0;
        //cout << bit << " " << sum << "\n";
        for(int i=0; i<20; i++){
            if((bit&(1<<i)) == 0) continue;
            //cout << (bit&(1<<i)) << " ";
            sum += pw[i];
            cnt++;
        }
        //cout << "\n";
        ump[sum] = cnt;
        if(sum == n){
            cout << cnt << " " << sum;
            return 0;
        }
        if(ump.find(sum-n) != ump.end()){
            //cout << sum << " " << abs(n-sum) << " " << n+(abs(n-sum)) << " " << ump[n+abs(n-sum)] << "\n";
            cout << ump[sum-n]+cnt << " " << sum;
            return 0;
        }
    }
    //cout << ump[10];
}
