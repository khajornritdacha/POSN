#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int key,dup;
        node *left, *right;
        node(int val){
            key = val;
            dup = 1;
            left = right = NULL;
        }
};

node* insert(int val, node* &now){
    if(now == NULL){
        now = new node(val);
    }else if(val < now->key){
        now->left = insert(val, now->left);
    }else if(val > now->key){
        now->right = insert(val, now->right);
    }else if(now->key == val){
        (now->dup)+=1;
    }
    return now;
}

node* find(int val, node* now){
    if(now == NULL)
        return NULL;
    if(val == now->key)
        return now;
    if(val < now->key)
        return find(val, now->left);
    return find(val, now->right);
}

node* findmin(node* now){
    if(now == NULL)
        return NULL;
    if(now->left != NULL)
        return findmin(now->left);
    return now;
}

node* findmax(node* now){
    if(now == NULL)
        return NULL;
    if(now->right != NULL)
        return findmax(now->right);
    return now;
}

void erase(int val, node* &now){
    if(now == NULL)
        return;
    if(val == now->key){
        node* tmp = now;
        if(now->left != NULL)
            now = now->left;
        else
            now = now->right;
        delete tmp;
    }else if(val < now->key){
        erase(val, now->left);
    }else{
        erase(val, now->right);
    }
}
void remove(int val, node* &now){
    if(now == NULL)
        return;
    if(val == now->key){
        if(now->dup-1 > 0){
            (now->dup)-=1;
            return;
        }
        if(now->left != NULL and now->right != NULL){
            node* leftmax = findmax(now->left);
            now->key = leftmax->key;
            now->dup = leftmax->dup;
            erase(leftmax->key, now->left);
        }else{
            node* tmp = now;
            if(now->left != NULL)
                now = now->left;
            else
                now = now->right;
            delete tmp;
        }
    }else if(val < now->key){
        remove(val, now->left);
    }else{
        remove(val, now->right);
    }
}
void inorder(node* now){
    if(now == NULL)
        return;
    inorder(now->left);
    cout << now->key << "("<<now->dup<<") ";
    inorder(now->right);
}

void preorder(node* now){
    if(now == NULL)
        return;
    cout << now->key << "("<<now->dup<<") ";
    preorder(now->left);
    preorder(now->right);
}

void postorder(node* now){
    if(now == NULL)
        return;
    postorder(now->left);
    postorder(now->right);
    cout << now->key << "("<<now->dup<<") ";
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    node* tr = NULL;
    /*int Q;
    cin >> Q;*/
    while(true){
        char code;
        int val;
        cin >> code >> val;
        if(code == 'X' and val == 0)
            break;
        if(code == 'I'){
            insert(val, tr);
        }else if(code == 'R'){
            remove(val, tr);
        }else if(code == 'F'){
            cout << "\n";
            node* tmp = find(val, tr);
            if(tmp != NULL){
                cout << "Y " << tmp->dup;
            }else{
                cout << "N";
            }
        }else{
            cout << "\n";
            if(val == 1)
                inorder(tr);
            else if(val == 2)
                preorder(tr);
            else
                postorder(tr);
        }
    }
}
