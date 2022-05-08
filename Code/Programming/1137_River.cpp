#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
long long sum,n;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        vec.emplace_back(temp);
    }
    long long a = vec[0],b = vec[1],c,d;
    sum+=vec[1];
    n-=2;
    while(n>=2){
        d = vec.back();
        vec.pop_back();
        c = vec.back();
        vec.pop_back();
        sum+=min(a+a+c+d,d+b+b+a);
        n-=2;
    }
    if(n==1){
        sum+=vec[2]+a;
    }
    cout << sum;
}
