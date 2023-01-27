#include <iostream>

using namespace std;


// Simple Example
class MyArray {
public:
    // constructor
    MyArray() : data(nullptr), len(0), cap(0) {}

    // destructor
    ~MyArray() { delete[] data; }

    // adds an element to the end of the array
    void push_back(int x) {
        if (len == cap) {
            resize(cap == 0 ? 1 : cap * 2);
        }
        data[len++] = x;
    }

    // removes the last element of the array
    void pop_back() {
        if (len > 0) {
            len--;
        }
    }

    // returns the element at a given index
    int operator[](int i) {
        return data[i];
    }

    // returns the size of the array
    int size() {
        return len;
    }

    // returns the capacity of the array
    int capacity() {
        return cap;
    }

private:
    int* data;
    int len;
    int cap;

    // resizes the array to the given capacity
    void resize(int new_cap) {
        int* new_data = new int[new_cap];
        for (int i = 0; i < len; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        cap = new_cap;
    }
};

int main() {
    MyArray arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.pop_back();
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
