#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int t;
main(){
    cin >> t;
    for(int tt=1; tt<=t; tt++){
        string str;
        bool ok = true;
        stack<char> st;
        cin >> str;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '(' or str[i] == '{' or str[i] == '['){
                st.push(str[i]);
            }else{
                if(st.empty()){
                    ok = false;
                }else{
                    if(str[i] == ')' and st.top() == '(')
                        st.pop();
                    else if(str[i] == '}' and st.top() == '{')
                        st.pop();
                    else if(str[i] == ']' and st.top() == '[')
                        st.pop();
                    else
                        ok = false;
                }
            }
        }
        if(ok and st.empty())
            cout << "yes";
        else
            cout << "no";
        cout << "\n";
    }
}
