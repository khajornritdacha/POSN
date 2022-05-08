#include<bits/stdc++.h>
using namespace std;
string str;
long long chua;
int n,cnt,mark;
stack<int> st;
vector<int> vec,rea,forfun[10005];
vector<int> temp,temp2,temp3;
void func(int i, int j){
    temp.clear();
    temp2.clear();
    temp3.clear();
    mark=-1;
    /*cout << cnt << " " << forfun[cnt].size() << "\n";
    for(int v : forfun[cnt])
        cout << v << " ";
    cout << "\n\n";*/
    for(int k=0; k<forfun[cnt].size(); k++){
        temp.emplace_back(forfun[cnt][k]);
        if(forfun[cnt][k]==3){
            mark=k+1;
        }
        if(k==mark){
            chua=temp.back();
            temp.pop_back();
            temp.pop_back();
            chua+=temp.back();
            temp.pop_back();
            chua=chua+(chua*16)/100;
            temp.emplace_back(chua);
            mark=-1;
        }
    }
    int sz=temp.size();
    for(int k=0; k<sz; k++){
        temp2.emplace_back(temp[k]);
        if(temp2.back()==2){
            mark=k+1;
        }
        if(mark==k){
            chua=temp2.back();
            temp2.pop_back();
            temp2.pop_back();
            chua+=temp2.back();
            temp2.pop_back();
            chua=chua+(chua*8)/100;
            temp2.emplace_back(chua);
            mark=-1;
        }
    }
    sz=temp2.size();
    for(int k=0; k<sz; k++){
        temp3.emplace_back(temp2[k]);
        if(temp3.back()==1){
            mark=k+1;
            //cout << "Mark: " << k << "\n";
        }
        if(mark==k){
            chua=temp3.back();
            temp3.pop_back();
            temp3.pop_back();
            chua+=temp3.back();
            temp3.pop_back();
            chua=chua+(chua*4)/100;
            //cout << "Con : " <<  k << " " << chua << "\n";
            temp3.emplace_back(chua);
            mark=-1;
        }
        /*for(int v : temp3)
            cout << v << " ";
        cout << "\n";*/
    }
    forfun[cnt-1].emplace_back(temp3.back());
    /*cout << "This is temp: ";
    for(int x : temp3)
        cout << x << " ";
    cout << "\n";*/
}
void cpy(){
    vector<int> storage;
    for(int i=0; i<vec.size(); i++){
        if(vec[i])
            storage.emplace_back(vec[i]);
    }
    vec=storage;
}
main(){
    cin >> str;
    n=str.size();
    for(int i=0; i<str.size(); i++){
        if(str[i]>='A'&&str[i]<='Z')
            vec.emplace_back(20);
        else if(str[i]>='0'&&str[i]<='9')
            vec.emplace_back(str[i]-'0');
        else if(str[i]=='['){
            vec.emplace_back(-1);
        }else if(str[i]==']'){
            vec.emplace_back(-2);
        }
    }
    for(int i=0; i<n; i++){
        if(vec[i]==-1){
            cnt++;
            st.push(i);
        }else if(vec[i]==-2){
            func(st.top()+1,i-1);
            cnt--;
            st.pop();
        }else{
            //cout << i << " " << cnt << '\n';
            forfun[cnt].emplace_back(vec[i]);
        }
    }
    vec=forfun[0];
    mark=-1;
    for(int i=0; i<vec.size(); i++){
        if(vec[i]==3){
            mark=i+1;
        }
        if(i==mark){
            chua=vec[i-2];
            chua+=vec[i];
            chua=chua+(chua*16)/100;
            vec[i]=chua;
            vec[i-2]=vec[i-1]=0;
        }
    }
    /*for(int v: vec)
        cout << v << " ";
    cout << "\n";*/
    cpy();
    mark=-1;
    for(int i=0; i<vec.size(); i++){
        if(vec[i]==2){
            mark=i+1;
        }
        if(i==mark){
            chua=vec[i-2];
            chua+=vec[i];
            chua=chua+(chua*8)/100;
            vec[i]=chua;
            vec[i-2]=vec[i-1]=0;
        }
    }
    /*for(int v: vec)
        cout << v << " ";
    cout << "\n";*/
    cpy();
    mark=-1;
    for(int i=0; i<vec.size(); i++){
        if(vec[i]==1){
            mark=i+1;
        }
        if(i==mark){
            chua=vec[i-2];
            chua+=vec[i];
            chua=chua+(chua*4)/100;
            vec[i]=chua;
            vec[i-2]=vec[i-1]=0;
        }
    }
    /*for(int v: vec)
        cout << v << " ";
    cout << "\n";*/
    cpy();
    cout << vec.front();
}
