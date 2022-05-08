#include <bits/stdc++.h>
using namespace std;

string str;
int ans = 0;
bool vi[10][10];

///Hint from CP handbook (Punning the search)

void solve(int lv, int r, int c, int pr, int pc){
    if(lv == 48){
        if(r == 7 and c == 1)
            ans++;
        return;
    }

    if(r == 7 and c == 1) return;
    if(r == 1 or r == 7){
        if(c != 1 and c != 7){
            if(!vi[r][c-1] and !vi[r][c+1]) return;
        }
    }
    if(c == 1 or c == 7){
        if(r != 1 and r != 7){
            if(!vi[r-1][c] and !vi[r+1][c]) return;
        }
    }

    if(1 < r and r < 7 and c > 1 and vi[r][c-1] and c-1 != pc and !vi[r+1][c] and !vi[r-1][c]){
        return;
    }
    if(1 < r and r < 7 and c < 7 and vi[r][c+1] and c+1 != pc and !vi[r+1][c] and !vi[r-1][c]){
        return;
    }
    if(1 < c and c < 7 and r > 1 and vi[r-1][c] and r-1 != pr and !vi[r][c-1] and !vi[r][c+1]){
        return;
    }
    if(1 < c and c < 7 and r < 7 and vi[r+1][c] and r+1 != pr and !vi[r][c-1] and !vi[r][c+1]){
        return;
    }

    if(str[lv] == '?' or str[lv] == 'D'){
        if(r+1 <= 7 and !vi[r+1][c]){
            vi[r+1][c] = true;
            solve(lv+1, r+1, c, r, c);
            vi[r+1][c] = false;
        }
    }
    if(str[lv] == '?' or str[lv] == 'U'){
        if(r-1 >= 1 and !vi[r-1][c]){
            vi[r-1][c] = true;
            solve(lv+1, r-1, c, r, c);
            vi[r-1][c] = false;
        }
    }
    if(str[lv] == '?' or str[lv] == 'L'){
        if(c-1 >= 1 and !vi[r][c-1]){
            vi[r][c-1] = true;
            solve(lv+1, r, c-1, r, c);
            vi[r][c-1] = false;
        }
    }
    if(str[lv] == '?' or str[lv] == 'R'){
        if(c+1 <= 7 and !vi[r][c+1]){
            vi[r][c+1] = true;
            solve(lv+1, r, c+1, r, c);
            vi[r][c+1] = false;
        }
    }
    return;
}

int main(void){
    cin >> str;
    vi[1][1] = true;
    solve(0, 1, 1, -1, -1);
    cout << ans << "\n";
    return 0;
}
