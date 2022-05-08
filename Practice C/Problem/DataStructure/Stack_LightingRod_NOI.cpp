#include <bits/stdc++.h>
using namespace std;

//https://oj.uz/problem/view/NOI18_lightningrod

inline void read(int& x) { //I copied it from someone in oj.uz
    x = 0;
    char ch = getchar_unlocked();
    while (ch&16){ //this will break when ‘\n’ or ‘ ‘ is encountered
		x = (x << 3) + (x << 1) + (ch&15);
		ch = getchar_unlocked();
	}
}

int main(void){
    int n; read(n);
    stack<pair<int, int>> st;

    for(int i = 1; i <= n; i++){
        int x, y; read(x), read(y);
        while(!st.empty() and x-st.top().first <= y-st.top().second) st.pop(); //remove every previous lighting rod that is covered by the current one
        if(st.empty() or (x-st.top().first > y-st.top().second and x-st.top().first > st.top().second-y)) st.push({x, y}); //add the current one if and only if it is not covered by the previous
    }

    printf("%d\n", st.size());

    return 0;
}
