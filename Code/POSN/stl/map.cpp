#include <bits/stdc++.h>
using namespace std;


int main(void){
    map<int, int> mp;
    mp[5] = 10;
    mp[2] = -1;
    mp[12] = 3;

    //Iteration
    {
        cout << "Iteration\n";
        for(auto &[key, val] : mp){
            cout << key << " " << val << "\n";
            val++;
        }

        cout << "Iteration (All values increased by 1 due to previous iteration)\n";
        for(auto [key, val] : mp){
            cout << key << " " << val << "\n";
        }

        cout << "Iteration with pointer (Both ways to get value from it is feasible)\n";
        for(auto it = mp.begin(); it != mp.end(); it++){
            cout << it->first << " " << (*it).second << "\n";
        }

        cout << "Reverse Iteration (Descending order by key)\n";
        for(auto it = mp.rbegin(); it != mp.rend(); it++){
            cout << it->first << " " << it->second << "\n";
        }
    }

    //Erase and Insert elements
    mp.erase(12);
    mp[-3] = 1;

    cout << "Erase and Insert\n";
    for(auto [key, val] : mp){
        cout << key << " " << val << "\n";
    }

    
    cout << "Size : " << mp.size() << "\n";   

    return 0;
}