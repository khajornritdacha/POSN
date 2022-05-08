#include<bits/stdc++.h>
using namespace std;
int n,last=-1,q;
vector<int> vec;
int lb(int val){
    int l=0,r=vec.size()-1,mid,ans=vec.size();
    while(l<=r){
        mid=(l+r)/2;
        if(vec[mid]>=val){
            ans=min(ans,mid);
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
int ub(int val){
    int l=0,r=vec.size()-1,mid,ans=vec.size();
    while(l<=r){
        mid=(l+r)/2;
        if(vec[mid]>val){
            ans=min(ans,mid);
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
main(){
    cin >> n;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(x==last) continue;
        vec.emplace_back(x);
        last=x;
    }
    cin >> q;
    for(int i=0; i<q; i++){
        int x;
        cin >> x;
        int k=lb(x);
        if(k==0)
            cout << "X ";
        else
            cout << vec[k-1] << " ";
        k=ub(x);
        if(k==vec.size())
            cout << "X\n";
        else
            cout << vec[k] << "\n";
    }
}
