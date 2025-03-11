#include <bits/stdc++.h>
using namespace std;

class PQ {
private:
    vector<int> _arr;

    int get_parent(int index) {
        return (index - 1)/2;
    }

    bool is_greater(int idx1, int idx2) {
        return _arr[idx1] > _arr[idx2];
    }
public:
    PQ() {
        _arr.clear();
    }

    void push(int x) {
        this->_arr.push_back(x);
        int idx = (int)this->_arr.size() - 1;
        while (idx > 0) {
            int par = get_parent(idx);
            if (!is_greater(idx, par)) {
                break;
            }
            swap(this->_arr[idx], this->_arr[par]);
            idx = par;
        }
    }

    bool empty() {
        return this->_arr.empty();
    }

    int top() {
        return this->_arr[0];
    }

    size_t size() {
        return this->_arr.size();
    }

    void pop() {
        this->_arr[0] = this->_arr.back();
        this->_arr.pop_back();

        int idx = 0;
        while (idx*2 + 1 < (int)_arr.size()) {
            int ch1 = idx * 2 + 1;
            int ch2 = idx * 2 + 2;

            int greater_ch = ch1;
            if (ch2 < (int)_arr.size() && is_greater(ch2, ch1)) {
                greater_ch = ch2;
            }

            if (is_greater(greater_ch, idx)) {
                swap(this->_arr[greater_ch], this->_arr[idx]);
                idx = greater_ch;
            } else {
                break;
            }
        }
    }
};

int main() {
    PQ pq;
    for (int i = 1; i <= 5; i++) {
        pq.push(i);
    }
    
    cout << "Size: " << pq.size() << "\n";
    while (!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
    }
}