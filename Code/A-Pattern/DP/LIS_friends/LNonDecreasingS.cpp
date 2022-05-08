#include<bits/stdc++.h>
using namespace std;
int n,a[10005],la,p[10005];
vector<int> lis,idx;
main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        int pos = lower_bound(lis.begin(),lis.end(),a[i]+1)-lis.begin();
        if(pos==lis.size()){
            lis.emplace_back(a[i]);
            idx.emplace_back(i);
            la = i;
        }else{
            lis[pos] = a[i];
            idx[pos] = i;
        }
        if(pos-1>=0){
            p[i] = idx[pos-1];
        }
    }
    vector<int> bt;
    while(la!=0){
        bt.emplace_back(a[la]);
        la = p[la];
    }
    for(int i=bt.size()-1;i>=0;i--)
        cout << bt[i] << " ";
}
