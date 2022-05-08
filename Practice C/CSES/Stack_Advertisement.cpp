#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
int n,a[N],lef[N],ler[N];
stack<int> st;
long long ans;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        while(!st.empty() and a[i] <= a[st.top()]){
            st.pop();
        }
        if(st.empty())
            lef[i] = 0;
        else
            lef[i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i=n; i>=1; i--){
        while(!st.empty() and a[i] <= a[st.top()]){
            st.pop();
        }
        if(st.empty())
            ler[i] = n+1;
        else
            ler[i] = st.top();
        st.push(i);
    }
    for(int i=1; i<=n; i++){
        //cout << lef[i] << " " << ler[i] << "\n";
        ans = max(ans, 1ll*(ler[i]-lef[i]-1)*a[i]);
    }
    cout << ans << "\n";
}

