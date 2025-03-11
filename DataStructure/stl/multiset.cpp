#include <bits/stdc++.h>
using namespace std;


int main(void){ 
    multiset<int> ss;
    ss.insert(1);
    ss.insert(1);
    ss.insert(1);
    ss.insert(1);
    ss.insert(1);
    ss.insert(1);
    ss.insert(1);

    cout << ss.size() << "\n";
    for(int s : ss) cout << s << " ";
    cout << "\n";

    
    // ss.erase(1);
    // cout << ss.size() << "\n";
    // for(int s : ss) cout << s << " ";


    ss.erase(ss.find(1));
    cout << ss.size() << "\n";
    for(int s : ss) cout << s << " ";

    return 0;
}
