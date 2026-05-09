#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

// 定義二元搜尋樹的節點結構
struct Node {
    int val;
    Node* left;
    Node* right;
    // 建構子
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Establish BST
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val); // find the correct position and insert the new node
    }
    if (val < root->val) {
        root->left = insert(root->left, val); // put smaller values on the left
    } else if (val > root->val) {
        root->right = insert(root->right, val); // put larger values on the right
    }
    return root; 
}

// 2. Post-order Traversal
int checkBalance(Node* root, bool& isBalanced, int& firstUnbalanced) {
    if (root == nullptr) {
        return 0;
    }

    // get the heights of left and right subtrees (from bottom to top)
    int left = checkBalance(root->left, isBalanced, firstUnbalanced);
    int right = checkBalance(root->right, isBalanced, firstUnbalanced);

    if (isBalanced) {
        if (abs(left - right) > 1) {
            isBalanced = false;           // mark as unbalanced
            firstUnbalanced = root->val;  // record the value of the first unbalanced node
        }
    }

    return max(left, right) + 1;
}

// 3. Level-order Traversal
void printLevelOrder(Node* root) {
    if (root == nullptr) return;
    
    queue<Node*> q;
    q.push(root);
    
    cout << "LEVEL-ORDER: ";
    bool isFirst = true; // control comma placement
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        if (!isFirst) cout << ", ";
        cout << current->val;
        isFirst = false;
        
        // enqueue left and right children if they exist
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    cout << "\n";
}

// release memory
void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ifstream infile("hw3_input.txt");
    if (!infile.is_open()) {
        cerr << "無法開啟 hw3_input.txt 檔案！" << endl;
        return 1;
    }

    string line;
    if (!getline(infile, line)) return 0;
    int T = stoi(line);

    while (T-- && getline(infile, line)) {
        Node* root = nullptr;
        stringstream ss(line);
        string token;

        // comma-separated values to build the BST
        while (getline(ss, token, ',')) {
            if (!token.empty()) {
                root = insert(root, stoi(token));
            }
        }

        bool isBalanced = true;
        int firstUnbalanced = 0;

        checkBalance(root, isBalanced, firstUnbalanced);

        if (isBalanced) {
            cout << "BALANCED\n";
        } else {
            cout << "UNBALANCED: " << firstUnbalanced << "\n";
        }

        printLevelOrder(root);

        freeTree(root);
    }

    infile.close();
    return 0;
}