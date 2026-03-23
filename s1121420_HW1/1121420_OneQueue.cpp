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

    int getSize() {
        return count;
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
    Queue* q;

public:
    Stack() {
        q = new Queue(1000); 
    }

    ~Stack() {
        delete q;
    }

    void push(int x) {
        int size = q->getSize();

        q->enqueue(x);

        for (int i = 0; i < size; i++) {
            int temp = q->dequeue();
            q->enqueue(temp);
        }
    }

    int pop() {
        if (q->isEmpty()) {
            return -1;
        }
        return q->dequeue();
    }

    int top() {
        if (q->isEmpty()) {
            return -1;
        }
        return q->getFront();
    }

    bool empty() {
        return q->isEmpty();
    }
};

int main() {
    Stack myStack;
    ifstream inputFile("hw1_input.txt");

    if (!inputFile.is_open()) {
        cout << "無法開啟檔案 hw1_input.txt，請確認檔案是否存在於相同目錄下。" << endl;
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