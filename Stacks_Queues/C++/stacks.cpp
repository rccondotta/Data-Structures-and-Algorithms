/*
this implementation has a time complexity of O(1) for push, pop and top operations
if you use a linked list or dynamic array the time complexity will be O(n)
*/
#include <iostream>
#include <vector>

class Stack {
    std::vector<int> data;

public:
    void push(int x) {
        data.push_back(x);
    }

    void pop() {
        if (!data.empty()) {
            data.pop_back();
        }
    }

    int top() {
        if (!data.empty()) {
            return data.back();
        }
        return -1;
    }

    bool empty() {
        return data.empty();
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    std::cout << s.top() << std::endl; // Output: 3
    s.pop();
    std::cout << s.top() << std::endl; // Output: 2
    s.pop();
    std::cout << s.top() << std::endl; // Output: 1
    s.pop();
    std::cout << s.empty() << std::endl; // Output: 1 (true)
    return 0;
}
