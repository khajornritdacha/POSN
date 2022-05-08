#include<bits/stdc++.h>
using namespace std;
long long n,k,a,cnta,cntb;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << setprecision(6) << fixed;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> a;
        if(a>=k)
            cntb++;
    }
    cnta=n-cntb;
    long long temp1=cntb*cnta*(cnta-1)/2;
    long long temp2=cnta*cntb*(cntb-1)/2;
    long long temp3=cntb*(cntb-1)*(cntb-2)/6;
    long long total=n*(n-1)*(n-2)/6;
    //cout << total << " " << temp1 << " " << temp2 << " " << temp3 << "\n";
    cout << (double)(temp1+temp2+temp3)/total;
}
