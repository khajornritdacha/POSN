#include<bits/stdc++.h>
using namespace std;

string str;
unordered_map<string, string> pa;
unordered_map<string, bool> vi;
queue<pair<string,int>> qq;
vector<int> shf[10];

main(){
    shf[0].emplace_back(1); shf[0].emplace_back(3);
    shf[1].emplace_back(0); shf[1].emplace_back(2); shf[1].emplace_back(4);
    shf[2].emplace_back(1); shf[2].emplace_back(5);
    shf[3].emplace_back(0); shf[3].emplace_back(4); shf[3].emplace_back(6);
    shf[4].emplace_back(1); shf[4].emplace_back(3); shf[4].emplace_back(5); shf[4].emplace_back(7);
    shf[5].emplace_back(2); shf[5].emplace_back(4); shf[5].emplace_back(8);
    shf[6].emplace_back(3); shf[6].emplace_back(7);
    shf[7].emplace_back(6); shf[7].emplace_back(4); shf[7].emplace_back(8);
    shf[8].emplace_back(5); shf[8].emplace_back(7);

    string want = "123456780";
    cin >> str;
    pa[str] = "-1";
    int pos;
    for(int i=0; i<str.size(); i++){
        if(str[i] == '0'){
            pos = i;
            break;
        }
    }

    qq.emplace(str, pos);
    while(!qq.empty()){
        string now = qq.front().first;
        pos = qq.front().second; ///position of blank
        //cout << now << " " << pos << " " << pa[now] << "\n";
        qq.pop();

        if(vi[now])
            continue;
        vi[now] = true;
        /*if(now == want)
            break;*/
        for(int i=0; i<shf[pos].size(); i++){
            string tmp = now;
            swap(tmp[shf[pos][i]], tmp[pos]);
            if(vi[tmp])
                continue;
            pa[tmp] = now;
            qq.emplace(tmp, shf[pos][i]);
        }
    }

    if(vi[want] == false){
        cout << "-1";
    }else{
        string now = want;
        stack<string> st;
        while(pa[now] != "-1"){
            st.emplace(now);
            now = pa[now];
        }
        st.emplace(str);
        while(!st.empty()){
            //cout << st.top() << "\n";
            for(int i=0; i<3; i++){
                for(int j=i*3; j<i*3+3; j++){
                    cout << st.top()[j];
                }
                cout << "\n";
            }
            cout << "\n";
            st.pop();
        }
    }
}
