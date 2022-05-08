#include <bits/stdc++.h>
using namespace std;

int pri(char x){
    if(x == '+' or x == '-') return 1;
    else if(x == '*' or x == '/') return 0;
}

int main(void){
    string res;
    stack<char> st;
    char str[1000010]; cin >> (str+1);
    int n = strlen(str+1);

    for(int i = 1; i <= n; i++){
        if(str[i] >= 'a' and str[i] <= 'z'){
            res += str[i];
        } else if (str[i] == '('){
            st.push(str[i]);
        } else if (str[i] == ')'){
            while(!st.empty() and st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() and pri(st.top()) <= pri(str[i])){
                res += st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while(!st.empty()){ res += st.top(); st.pop(); }

    cout << res << "\n";

    return 0;
}