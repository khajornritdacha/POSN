#include <bits/stdc++.h>
using namespace std;


int main(void){
    //Unordered_map basically is a hash table.
    //So, keys in unordered_map is not sorted.
    //The advantage of using unordered_map is that you can access any element in O(1) while map is O(logN).
    //But you have to trade off with unsorted key.
    unordered_map<int, int> ump;

    ump[5] = 1;
    ump[1] = -3;
    ump[-1] = 10;

    cout << "Size : " << ump.size() << "\n";

    cout << "Iteration (Add & to change actual values)\n";
    for(auto &[key, val] : ump){
        cout << key << " " << val << "\n";
        val++;
    }

    cout << "Another Iteration\n";
    for(auto [key, val] : ump){
        cout << key << " " << val << "\n";
    }

    cout << "Iteration with pointer\n";
    for(auto it = ump.begin(); it != ump.end(); it++){
        cout << it->first << " " << it->second << "\n";
    }


    return 0;
}