#include <bits/stdc++.h>
using namespace std;


int main(void){
    set<int> ss = {1, 3, 10, 12, 20};
    cout << "Size : " << ss.size() << "\n";
    cout << "End of set: " << *ss.end() << "\n"; //Size of set

    //Iteration
    {
        for(int s : ss){
            cout << s << " ";
        }
        cout << "\n";

        for(auto it = ss.begin(); it != ss.end(); it++){
            cout << *it << " ";
        }
        cout << "\n";

        for(auto s : ss){ //s is int type
            cout << s << " ";
        }
        cout << "\n";
    }

    //insert and erase
    ss.insert(2);
    ss.erase(12);


    //Reverse iteration
    for(auto it = ss.rbegin(); it != ss.rend(); it++){
        cout << *it << " ";
    }
    cout << "\n";


    //O(logN)
    //Lower bound -> find the minimum element that is equal or greater than x (>= x)
    int k1 = *(ss.lower_bound(30)); 
    auto it = ss.lower_bound(30) // = ss.end()
    if(it != ss.end()){
        //available
    }

    cout << "Lower bound : " << k1 << "\n";
    //Upper bound -> find the minimum element that is greater than x (> x)
    int k2 = *(ss.upper_bound(10));
    cout << "Upper bound : " << k2 << "\n";

    //Upper bound-- -> Find the maximum element that is equal or less than x (<= x)
    int k3 = *(--ss.upper_bound(10)); 
    cout << "Upper bound-- : " << k3 << "\n";

    auto tmp = (ss.upper_bound(-1));
    if(tmp != ss.begin()){
        tmp--;
        k3 = *tmp;
    }
    //Lower bound-- -> Find the maximum element that is less than x (< x)
    int k4 = *(--ss.lower_bound(10));
    cout << "Lower bound-- : " << k4 << "\n";



    
    //Set sorted in descending order
    set<int, greater<int>> max_set = {1, 2, 3, 4, 5};
    for(int s : max_set){
        cout << s << " ";
    }
    cout << "\n";
}