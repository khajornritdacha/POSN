#include<bits/stdc++.h>
using namespace std;
int n,a[10005],la,p[10005];
vector<int> lis,idx;
///Longest Decreasing Subsquence
main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=n;i>=1;i--){
        int pos = lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
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
    for(int i=0;i<bt.size();i++)
        cout << bt[i] << " ";
}
