#include <bits/stdc++.h>
using namespace  std;


int main(void){
    //push, pop, front, size, empty
    queue<int> qq;

    for(int i = 20; i >= 10; i--){
        qq.push(i);
    }

    cout << "Size : " << qq.size() << "\n";
    cout << "Front element : " << qq.front() << "\n";

    cout << "Iterate queue in order\n";
    while(!qq.empty()){ //empty return 0 if queue is not empty and 1 if queue is empty.
        cout << qq.front() << " ";
        qq.pop();
    }
    cout << "\n";

    return 0;
}