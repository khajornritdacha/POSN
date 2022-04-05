#include <bits/stdc++.h>
using namespace std;


int main(void){
    //push, top, size, empty
    stack<int> st;

    for(int i = 20; i >= 10; i--){
        st.push(i);
    }

    cout << "Size : " << st.size() << "\n";
    cout << "Top : " << st.top() << "\n";

    cout << "Iterate through stack\n";
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }


    return 0;
}