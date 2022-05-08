#include<bits/stdc++.h>
using namespace std;
int n;
stack<char> st;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        char x;
        cin >> x;
        if(!st.empty() and x == st.top())
            st.pop();
        else
            st.push(x);
    }
    cout << st.size() << "\n";
    if(st.empty())
        cout << "empty\n";
    else
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
}
