#include <bits/stdc++.h>
using namespace std;

int main() {
    //push, top, pop, size, empty
    //Priority_queue is a heap
    //By default it is a max heap
    
    priority_queue<int> pq;

    for (int i = 1; i <= 5; i++) {
        pq.push(i); // Add elements to PQ
    }
    
    cout << "Size: " << pq.size() << "\n";
    cout << "Maximum element : " << pq.top() << "\n";
    
    cout << "Iterate through pq (Get element in decreasing order)\n";
    while (!pq.empty()) { // Check if pq is empty
        cout << pq.top() << "\n"; // Print the maximum value
        pq.pop(); // Remove the maximum value
    }
}
// Output
// Size: 5
// 5 4 3 2 1