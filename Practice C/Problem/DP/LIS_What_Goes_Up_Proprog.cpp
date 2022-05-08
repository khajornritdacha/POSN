#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int i=1,idx[N],bt[N],a[N];
stack<int> st;
vector<int> lis;
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    while(cin >> a[i]){
        int k = lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
        if(k==lis.size()){
            lis.push_back(a[i]);
        }else{
            lis[k]=a[i];
        }
        idx[k]=i;
        if(k>0)
            bt[i]=idx[k-1];
        i++;
    }
    /*for(int j=0; j<=i; j++)
        cout << idx[j] << " ";
    cout << "\n";
    for(int j=0; j<=i; j++)
        cout << bt[j] << " ";
    cout << "\n\n";*/
    cout << lis.size() << "\n-\n";
    int now=idx[lis.size()-1];
    while(now!=0){
        //cout << a[now] << " ";
        st.push(a[now]);
        now=bt[now];
    }
    while(!st.empty()){
        cout << st.top() << "\n";
        st.pop();
    }
}
