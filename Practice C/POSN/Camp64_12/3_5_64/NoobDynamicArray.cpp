#include<bits/stdc++.h>
using namespace std;

string* deleteLast(string a[], int &sz){
    string* b = new string[sz-1];
    for(int i=0; i<sz-1; i++){
        b[i] = a[i];
    }
    sz--;
    return b;
}

string* deleteFirst(string a[], int &sz){
    string* b = new string[sz-1];
    for(int i=1; i<sz; i++){
        b[i-1] = a[i];
    }
    sz--;
    return b;
}

string* del(string a[], int &sz, int pos){
    string* b = new string[sz-1];
    int p = 0;
    for(int i=0; i<pos; i++, p++){
        b[p] = a[i];
    }
    for(int i=pos+1; i<sz; i++, p++){
        b[p] = a[i];
    }
    sz--;
    return b;
}

string* del(string a[], int &sz, int pos1, int pos2){
    string* b = new string[sz-(pos2-pos1+1)];
    int p = 0;
    for(int i=0; i<pos1; i++, p++){
        b[p] = a[i];
    }
    for(int i=pos2+1; i<sz; i++, p++){
        b[p] = a[i];
    }
    sz -= pos2-pos1+1;
    return b;
}

string* addFirst(string a[], int &sz, string val){
    string* b = new string[sz+1];
    b[0] = val;
    for(int i=0; i<sz; i++){
        b[i+1] = a[i];
    }
    sz++;
    return b;
}

string* addFirst(string a[], int &sz1, string b[], int &sz2){
    string* c = new string[sz1+sz2];
    for(int i=0; i<sz2; i++){
        c[i] = b[i];
    }
    for(int i=0; i<sz1; i++){
        c[sz2+i] = a[i];
    }
    sz1 += sz2;
    return c;
}

string* ins(string a[], int &sz, string val, int pos){
    string* b = new string[sz+1];
    int p = 0;
    b[pos] = val;
    for(int i=0; i<pos; i++, p++){
        b[i] = a[p];
    }
    for(int i=pos+1; p<sz; i++, p++){
        b[i] = a[p];
    }
    sz++;
    return b;
}

void pri(string a[], int sz){
    for(int i=0; i<sz; i++){
        cout << a[i] << " \n"[i==sz-1];
    }
    cout << "-----------------\n";
}

main(){
    string *x = { new string[5]{"A", "B", "C", "D", "E"} };
    int sz = 5;
    pri(x, sz);

    cout << "Delete First : ";
    x = deleteFirst(x, sz);
    pri(x, sz);

    cout << "Delete Last : ";
    x = deleteLast(x, sz);
    pri(x, sz);

    cout << "AddFirst(1 Element) : ";
    x = addFirst(x, sz, "Jomnoi");
    pri(x, sz);

    cout << "Delete : ";
    x = del(x, sz, 3);
    pri(x, sz);

    cout << "Insert : ";
    x = ins(x, sz, "Jim", 1);
    pri(x, sz);

    cout << "AddFirst(Array) : ";
    string y[] = {"BA", "Jar", "Kim"};
    int sz2 = 3;
    x = addFirst(x, sz, y, sz2);
    pri(x, sz);

    cout << "Delete(Interval) : ";
    x = del(x, sz, 2, 4);
    pri(x, sz);
}
