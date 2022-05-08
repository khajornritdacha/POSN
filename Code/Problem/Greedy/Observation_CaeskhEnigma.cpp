#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

vector<int> order;

///Greedy by finding 'pos' such that it is the right most index which can be greater than input and try to minimize the right side of pos
///https://beta.programming.in.th/tasks/tumso17_enigma

void cal(int idx){
    order[idx] *= 10;
    if(order[idx+1] > 10){
        order[idx] += order[idx+1]/10;
        order[idx+1] %= 10;
    }else{
        order[idx] += order[idx+1];
        order[idx+1] = 0;
    }
}

int main(void){
    string str, ans;

    cin >> str;
    for(int i = 0; str[i] != '\0'; i++){
        order.push_back(str[i]-'A'+1);
    }

    if(DEBUG){
        for(int ord : order){
            cout << ord << " ";
        }
        cout << "\n";
    }

    int pos = -1;
    for(int i = (int)order.size()-2; i >= 0; i--){
        if(order[i+1]%10 == 0) continue;
        if(order[i] == 1){
            pos = i;
            cal(i);
            break;
        }else if(order[i] == 2){
            if(order[i+1] > 10 or order[i+1] <= 6){
                cal(i);
                pos = i;
                break;
            }
        }
    }

    assert(pos != -1);

    if(DEBUG){
        for(int ord : order){
            cout << ord << " ";
        }
        cout << "\n";
    }

    for(int i = 0; i <= pos; i++)
        ans.push_back(char(order[i]+'A'-1));
    for(int i = pos+1; i < order.size(); i++){
        if(i == pos+1 and order[i] == 0) continue;
        if(order[i]%10 != 0){
            if(order[i] > 10){
                ans.push_back(char(order[i]/10+'A'-1));
            }
            ans.push_back(char(order[i]%10+'A'-1));
        }else{
            ans.push_back(char(order[i]+'A'-1));
        }
    }
    cout << ans << "\n";

    return 0;
}
