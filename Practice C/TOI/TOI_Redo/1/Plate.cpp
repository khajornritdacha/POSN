#include<bits/stdc++.h>
using namespace std;

/*
Lang: C++
TASK: Plate
AUTHOR: Mahathep JomnoiZ
CENTER: SU Number 1
*/

const int N = 1010;

queue<int> qa; //Overall class
queue<int> qec[15]; //Queue inside each class
int NC,n,sc_id[N];
bool inQ[15];

int main(void){
    scanf(" %d %d", &NC, &n);

    for(int i = 1; i <= n; i++){
        int x,y; scanf(" %d %d", &x, &y);
        sc_id[y] = x;
    }

    while(true){
        char code; scanf(" %c", &code);
        if(code == 'X'){ printf("0\n"); return 0;}
        if(code == 'E'){
            int now; scanf(" %d", &now);
            int cla = sc_id[now];
            if(!inQ[cla]){
                inQ[cla] = true;
                qa.push(cla);
            }
            qec[cla].push(now);
        }else{
            if(qa.empty()){
                printf("empty\n");
            }else{
                int front_class = qa.front();
                printf("%d\n", qec[front_class].front());
                qec[front_class].pop();
                if(qec[front_class].empty()){
                    inQ[front_class] = false;
                    qa.pop();
                }
            }
        }
    }
    return 0;
}
