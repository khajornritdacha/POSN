#include<bits/stdc++.h>
using namespace std;
long long n,s;
vector<int> vec;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        cin >> n >> s;
        if(n==EOF||s==EOF)
            return 0;
        for(int i=0;i<n;i++){
            int a;
            cin >> a;
            vec.emplace_back(a);
        }
        int temp=0,chua=0,minn=1e9;
        for(int i=0;i<vec.size();i++){
            temp+=vec[i];
            chua++;
            if(temp>=s){
                while(temp>=s&&chua>0){
                    if(chua<minn){
                        minn = chua;
                    }
                    temp-=(vec[i-chua+1]);
                    chua--;
                }
            }
        }
        if(minn!=1e9)
            cout << minn << '\n';
        else
            cout << 0 << '\n';
        vec.clear();
    }
}
