#include<bits/stdc++.h>
#define DEBUG false
using namespace std;

const int N = 2e5+10;
using pi = pair<int,int>;
int n,a[N];
stack<int> st;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        while(!st.empty() and a[st.top()] >= a[i])
            st.pop();
        if(st.empty())
            cout << "0";
        else
            cout << st.top();
        st.push(i);
        cout << " ";
    }
}

