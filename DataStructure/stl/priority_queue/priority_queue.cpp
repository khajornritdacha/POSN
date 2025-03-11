#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq;

    for (int i = 1; i <= 5; i++) {
        pq.push(i); // Add elements to PQ
    }

    cout << "Size: " << pq.size() << "\n";

    while (!pq.empty()) { // Check if pq is empty
        cout << pq.top() << "\n"; // Print the maximum value
        pq.pop(); // Remove the maximum value
    }
}
// Output
// Size: 5
// 5 4 3 2 1