#include <bits/stdc++.h>
#define DEBUG false
using namespace std;

//delete elements first
//use Small to Large merge to help merge set and maintain List 
//then concatenate list 

const int N = 1e5+10, INF = 2e9;
using pi = pair<int, int>;

struct node{
    int v, h, t, pid; //val, its head, its tail, respectively
    bool ish, ist; //is head
};

struct PR{
    int idh, idt; //idx of head, tail
};

struct query{
    int cd, x, y; 
};

int K, M, sz[N], idx, ch[N]; //ch -> current head
set<pi> ss[N];

node ele[N];
PR pr[N];
query qq[N];

void rem(int id){ //remove node
    // cout << id << " = " << ele[id].v << " " << ele[id].ish << " " << ele[id].ist << "\n";
    if(ele[id].ish){
        int tid = ele[id].t;
        pr[ele[id].pid].idh = tid;
        if(ele[id].t != -1){ //change pr
            ele[tid].h = ele[id].h;
            ele[tid].pid = ele[id].pid;
            ele[tid].ish = true;
        }

        if(ele[id].ist){
            pr[ele[id].pid].idt = -1;
        }
    } else {
        if(ele[id].ist){
            pr[ele[id].pid].idt = ele[id].h;
            ele[ele[id].h].pid = ele[id].pid;
            ele[ele[id].h].ist = true;
        }

        ele[ele[id].h].t = ele[id].t;
        if(ele[id].t != -1)
            ele[ele[id].t].h = ele[id].h;
    }
}

void erase(int id, int v){ //erase elements from set
    if(id == -1) return;
    while(!ss[id].empty()){
        auto it = ss[id].lower_bound(pi(v, -INF));
        if(it == ss[id].end() or it->first != v) break;
        rem(it->second);
        ss[id].erase(it);
    }
}

void merge(int i, int j){ //merge 2 sets with Small to Large merge technique
    if(ch[j] == -1) return;
    if(ch[i] == -1 and ch[j] != -1){ ch[i] = ch[j], ch[j] = -1; return; }

    //this mean both ch[i] and ch[j] != -1
    if(ss[ch[i]].size() < ss[ch[j]].size()){
        swap(ch[i], ch[j]); //let i be the bigger one
    }
    
    for(auto [x, y] : ss[ch[j]]){
        ss[ch[i]].insert(pi(x, y));
    }
    ss[ch[j]].clear();
    ch[j] = -1;
}

void con(int i, int j){
    if(pr[j].idh == -1) return;
    if(pr[i].idh == -1){ 
        pr[i].idh = pr[j].idh;
        pr[i].idt = pr[j].idt;
        pr[j].idh = pr[j].idt = -1;
        return; 
    }
    int nh = pr[i].idt, nt = pr[j].idh;
    ele[nh].t = nt;
    ele[nh].ist = false;
    ele[nt].h = nh;
    ele[nt].ish = false;

    pr[i].idt = pr[j].idt;
    pr[j].idh = pr[j].idt = -1;
}

void chk1(){
    cout << "\nCheck elements\n";
    for(int k = 1; k <= K; k++){
        cout << ch[k] << " : ";
        if(ch[k] < 0) { cout << "\n"; continue; }
        for(auto [x, y] : ss[ch[k]]) cout << x << " ";
        cout << "\n";
    }
    cout << "\n";
}

void chk2(){
    cout << "\nCheck List\n";
    for(int k = 1; k <= K; k++){
        cout << pr[k].idh << " " << k << " : ";
        if(pr[k].idh < 0){ cout << "\n"; continue; }
        int id =  pr[k].idh;
        while(id != -1){ 
            cout << ele[id].v << " ";
            id = ele[id].t;
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(void){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> K >> M;
    for(int k = 1; k <= K; k++){
        ch[k] = k;
        
        cin >> sz[k];
        assert(sz[k] > 0);
        for(int i = 1; i <= sz[k]; i++){
            int val; cin >> val;
            
            ++idx;
            ele[idx].h = -1, ele[idx].ish = ele[idx].ist = 0, ele[idx].t = -1, ele[idx].pid = -1;
            ele[idx].v = val;

            if(i == 1){
                ele[idx].ish = true; //set to false if it is merged to others
                ele[idx].h = -1;
                ele[idx].pid = k;
                pr[k].idh = idx;
            } else {
                ele[idx].h = idx-1;
            }

            if(i == sz[k]){
                ele[idx].ist = true;
                ele[idx].t = -1;
                ele[idx].pid = k;
                pr[k].idt = idx;
            } else {
                ele[idx].t = idx+1;
            }

            ss[k].insert(pi(val, idx));
        }
    }

    for(int i = 1; i <= M; i++){
        int x, y, z; cin >> x >> y >> z;
        qq[i] = {x, y, z};

        if(x == 1){
            if(ch[y] == -1) continue;
            erase(ch[y], z);
            if(ss[ch[y]].empty()) ch[y] = -1;
        } else if(x == 2){
            merge(y, z);
        }

        if(DEBUG){
            chk1();
            chk2();
        }

    }

    for(int i = 1; i <= M; i++){
        if(qq[i].cd == 1) continue;
        con(qq[i].x, qq[i].y);
    }

    for(int i = 1; i <= K; i++){
        int id = pr[i].idh;
        while(id != -1){
            cout << ele[id].v << "\n";
            id = ele[id].t;
        }
    }

    return 0;
}