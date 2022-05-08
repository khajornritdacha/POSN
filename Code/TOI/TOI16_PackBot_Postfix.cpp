#include<bits/stdc++.h>
#define DEBUG false
using namespace std;
vector<int> vec;
stack<int> st;
string str;
main(){
    cin >> str;
    for(int i=0; i<str.size(); i++){
        if(isalpha(str[i])){
            vec.emplace_back(20);
        }else if(str[i] =='['){
            st.push(-1);
        }else if(str[i] == ']'){
            while(!st.empty() and st.top() != -1){
                vec.emplace_back(st.top());
                st.pop();
            }
            st.pop();
        }else{
            int now = str[i]-'0';
            while(!st.empty() and st.top() >= now){
                vec.emplace_back(st.top());
                st.pop();
            }
            st.push(now);
        }
    }
    while(!st.empty()){
        vec.emplace_back(st.top());
        st.pop();
    }
    if(DEBUG){
        for(int v : vec){
            cout << v << " ";
        }
    }
    stack<int> last;
    for(int i=0; i<vec.size(); i++){
        if(vec[i] <= 3){
            int val1 = last.top();
            last.pop();
            int val2 = last.top();
            last.pop();
            int res = val1+val2;
            if(vec[i] == 3)
                res = (res*116)/100;
            else if(vec[i] ==2)
                res = (res*108)/100;
            else
                res = (res*104)/100;
            last.push(res);
        }else{
            last.push(vec[i]);
        }
    }
    cout << last.top();
}
