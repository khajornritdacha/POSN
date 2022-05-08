#include<bits/stdc++.h>
using namespace std;

int ans;
string str;
stack<int> st;

main(){
    cin >> str;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '(')
            st.push(str[i]);
        else{
            if(!st.empty())
                st.pop();
            else
                ans++;
        }
    }
    ans += st.size();
    cout << ans;
}
