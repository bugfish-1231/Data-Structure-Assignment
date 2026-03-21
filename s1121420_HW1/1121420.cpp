#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Queue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size = 1000) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == capacity);
    }

    void enqueue(int item) {
        if (isFull()) {
            return; 
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1; 
        }
        int item = arr[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }
};

class Stack {
private:
    Queue* q1;
    Queue* q2;

public:
    Stack() {
        q1 = new Queue(1000); 
        q2 = new Queue(1000);
    }

    ~Stack() {
        delete q1;
        delete q2;
    }

    void push(int x) {
        // 新元素放入空的 q2
        q2->enqueue(x);

        // 將 q1 的所有元素移到 q2 確保新元素在最前面
        while (!q1->isEmpty()) {
            q2->enqueue(q1->dequeue());
        }

        // 交換 q1 與 q2 的指標 (O(1) 的時間複雜度)
        Queue* temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop() {
        if (q1->isEmpty()) {
            return -1;
        }
        return q1->dequeue();
    }

    int top() {
        if (q1->isEmpty()) {
            return -1;
        }
        return q1->getFront();
    }

    bool empty() {
        return q1->isEmpty();
    }
};

int main() {
    Stack myStack;
    ifstream inputFile("hw1_input.txt");              // hw1_input2.txt hw1_input3.txt 

    if (!inputFile.is_open()) {
        cout << "無法開啟檔案 hw1_input.txt" << endl;
        return 1;
    }

    string command;
    while (inputFile >> command) {
        if (command == "push") {
            int value;
            inputFile >> value;
            myStack.push(value);
        } 
        else if (command == "pop") {
            if (!myStack.empty()) {
                cout << myStack.pop() << endl;
            }
        } 
        else if (command == "top") {
            if (!myStack.empty()) {
                cout << myStack.top() << endl;
            }
        } 
        else if (command == "empty") {
            if (myStack.empty()) {
                cout << "True" << endl;
            } else {
                cout << "False" << endl;
            }
        } 
        else if (command == "exit") {

            cout << endl;

            while (!myStack.empty()) {
                myStack.pop();
            }
        }
    }

    inputFile.close();
    return 0;
}