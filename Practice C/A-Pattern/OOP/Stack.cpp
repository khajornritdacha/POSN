#include<bits/stdc++.h>
using namespace std;

class ST{

    class node{
        public:
        int val;
        node* pa;
            node(int val){
                this->val = val;
                pa = NULL;
            }
    };
    node* head;
    int sz;

    public:

    ST(){
        head = NULL;
        sz = 0;
    }

    void push(int val){
        node* tmp = new node(val);
        node* chua;
        if(head == NULL){
            head = tmp;
        }else{
            tmp->pa = head;
            head = tmp;
        }
        sz++;
    }

    void pop(){
        if(sz == 0)
            return;
        sz--;
        node* tmp = head;
        head = head->pa;
        delete tmp;
    }

    int size(){
        return sz;
    }

    int top(){
        return head->val;
    }

    void pr(node* now){
        if(now != NULL)
            cout << now->val << " ";
        pr(now->pa);
    }
    void pri(){
        pr(head);
    }
};

main(){
    ST st;
    st.push(2);
    cout << st.top() << " " << st.size() << "\n";
    st.push(7);
    st.push(3);
    cout << st.top() << " " << st.size() << "\n";

    st.pop();
    cout << st.top() << " " << st.size() << "\n";

    st.pop();
    cout << st.top() << " " << st.size() << "\n";

}
