#include<bits/stdc++.h>
using namespace std;
stack <char> st;
string str;
char c;
int n,ans=0;
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> str;
    n = str.size();
    for(int i=0;i<n;i++){
        c = str[i];
        if(c=='('){
            st.push(c);
        }else if(c==')'){
            if(!st.empty()){
                st.pop();
            }else{
                ans++;
            }
        }
    }
    while(!st.empty()){
        ans++;
        st.pop();
    }
    cout << ans;
}
