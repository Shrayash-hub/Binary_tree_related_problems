#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Iterative tree creation using queue (level order)
Node* createTree() {
    int x;
    cout << "Enter root data (-1 for no node): ";
    cin >> x;
    if (x == -1) return NULL;

    Node* root = new Node(x);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << " (-1 for no node): ";
        cin >> x;
        if (x != -1) {
            temp->left = new Node(x);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << " (-1 for no node): ";
        cin >> x;
        if (x != -1) {
            temp->right = new Node(x);
            q.push(temp->right);
        }
    }
    return root;
}



int main() {
    Node* root = createTree();
    return 0;
}
