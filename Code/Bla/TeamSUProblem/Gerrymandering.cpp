#include<bits/stdc++.h>
using namespace std;
int V,E,P,Q,win,pa[100010],secwin,point[100010],cmp[100010];
bool cd;
long long mx,p[100010][55];
stack<int> st;
set<int> ps;
set<pair<int,int>> s;
vector<pair<int,int>> edge,ques;
int _fi(int x){
    if(pa[x]==x) return x;
    return pa[x]=_fi(pa[x]);
}
bool uni(int u, int v,bool code=false){
    u=_fi(u);
    v=_fi(v);
    if(u!=v){
        pa[u]=v;
        ps.erase(u);
        for(int i=1; i<=P; i++){
            p[v][i]+=p[u][i];
        }
        if(code==0) return true;
        point[cmp[u]]--;
        point[cmp[v]]--;
        cd=0;
        mx=0;
        secwin=0;
        for(int i=1; i<=P; i++){
            if(p[v][i]>mx){
                mx=p[v][i];
                secwin=i;
                cd=0;
            }else if(p[v][i]==mx){
                cd=1;
            }
        }
        if(cd==0){
            point[secwin]++;
            cmp[v]=secwin;
        }else{
            cmp[v]=0;
        }
        win=-1;
        mx=0;
        for(int i=1; i<=P; i++){
            if(point[i]>mx){
                mx=point[i];
                win=i;
            }else if(point[i]==mx){
                win=-1;
            }
        }
        st.push(win);
        return true;
    }
    return false;
}
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> V >> E >> P >> Q;
    for(int i=1; i<=V; i++){
        for(int j=1; j<=P; j++){
            cin >> p[i][j];
        }
        pa[i]=i;
        ps.insert(i);
    }
    for(int i=1; i<=E; i++){
        int u,v;
        cin >> u >> v;
        if(u>v)
            swap(u,v);
        edge.emplace_back(u,v);
    }
    for(int i=1; i<=Q; i++){
        int u,v;
        cin >> u >> v;
        if(u>v)
            swap(u,v);
        s.insert({u,v});
        ques.emplace_back(u,v);
    }
    for(auto ed : edge){
        if(s.find(ed)!=s.end()) continue;
        uni(ed.first,ed.second);
    }
    for(auto it=ps.begin(); it!=ps.end(); it++){
        cd=0;
        mx=0;
        secwin=0;
        for(int i=1; i<=P; i++){
            if(p[*it][i]>mx){
                mx=p[*it][i];
                secwin=i;
                cd=0;
            }else if(p[*it][i]==mx){
                cd=1;
            }
        }
        if(cd==0){
            point[secwin]++;
            cmp[*it]=secwin;
        }else{
            cmp[*it]=0;
        }
    }
    win=-1;
    mx=0;
    for(int i=1; i<=P; i++){
        if(point[i]>mx){
            mx=point[i];
            win=i;
        }else if(point[i]==mx){
            win=-1;
        }
    }
    st.push(win);
    for(int i=ques.size()-1; i>0; i--){
        if(!uni(ques[i].first,ques[i].second,1)){
            st.push(st.top());
        }
    }
    while(!st.empty()){
        cout << st.top() << "\n";
        st.pop();
    }
}
