#include<bits/stdc++.h>
using namespace std;


int top[310];
string str;
stack<char> st;
vector<char> use;

main(){
    top['+'] = top['-'] = 1;
    top['*'] = top['/'] = 2;
    top['^'] = 3;
    cin >> str;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '('){
            st.push(str[i]);
            continue;
        }
        if(str[i] == ')'){
            while(st.top() != '('){
                use.emplace_back(st.top());
                st.pop();
            }
            st.pop();
            continue;
        }

        if(!top[str[i]]){
            use.emplace_back(str[i]);
        }else{
            while(!st.empty() and top[st.top()] >= top[str[i]]){
                use.emplace_back(st.top());
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.empty()){
        use.emplace_back(st.top());
        st.pop();
    }

    for(char c : use)
        cout << c;
    cout << "\n";

    vector<int> rea;
    for(int i=0; i<use.size(); i++){
        char now = use[i];
        if('0' <= now and now <= '9'){
            rea.emplace_back(now-'0');
        }else{
            char n1 = rea.back();
            rea.pop_back();
            char n2 = rea.back();
            rea.pop_back();
            int res;
            if(now == '+')
                res = n2+n1;
            else if(now == '-')
                res = n2-n1;
            else if(now == '*')
                res = n2*n1;
            else
                res = n2/n1;
            rea.emplace_back(res);
        }
    }
    cout << rea.front();
}


