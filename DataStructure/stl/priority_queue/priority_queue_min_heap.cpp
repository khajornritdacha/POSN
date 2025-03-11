#include <bits/stdc++.h>
using namespace std;

void minimum_pq1() {
    priority_queue<int> pq;

    for (int i = 1; i <= 5; i++) {
        pq.push(i * -1); // Add elements to PQ
    }

    cout << "Size: " << pq.size() << "\n";
    cout << "Minimum element : " << -1 * pq.top() << "\n";
    
    cout << "Iterate through pq (Get element in ascending order)\n";
    while (!pq.empty()) { // Check if pq is empty
        cout << -1 * pq.top() << " "; // Print the minimum value
        pq.pop(); // Remove the minimum value
    }
}

void minimum_pq2(){
    //We can modify the comparator inside priority queue so that the top element is the minimum element
    priority_queue<int, vector<int>, greater<int>> pq;
     for(int i = 1; i <= 5; i++){
        pq.push(i);
    }

    cout << "Size : " << pq.size() << "\n";
    cout << "Minimum element : " << pq.top() << "\n";
    
    cout << "Iterate through pq (Get element in ascending order)\n";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main(void){
    minimum_pq1();
    
    cout << "\n------------------------------------------\n";
    
    minimum_pq2();   
    return 0;
}