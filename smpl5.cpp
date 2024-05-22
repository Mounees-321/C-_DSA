#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node() : key(0), left(nullptr), right(nullptr) {}
    Node(int data) : key(data), left(nullptr), right(nullptr) {}
};

Node* Root = nullptr;

class AVL {
public:
    int height(Node* root) {
        if (!root)
            return -1;
        return 1 + max(height(root->left), height(root->right));
    }

    int BalanceFactor(Node* root) {
        if (!root)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return lh - rh;
    }

    bool is_Balanced(Node* root) {
        if (!root)
            return true;

        int lh = height(root->left);
        int rh = height(root->right);

        return abs(lh - rh) <= 1 && is_Balanced(root->left) && is_Balanced(root->right);
    }

    Node* LLrotate(Node* root) {
        Node* newRoot = root->left;
        root->left = newRoot->right;
        newRoot->right = root;
        return newRoot;
    }

    Node* RRrotate(Node* root) {
        Node* newRoot = root->right;
        root->right = newRoot->left;
        newRoot->left = root;
        return newRoot;
    }

    Node* LRrotate(Node* root) {
        root->left = RRrotate(root->left);
        return LLrotate(root);
    }

    Node* RLrotate(Node* root) {
        root->right = LLrotate(root->right);
        return RRrotate(root);
    }

    Node* Insert(Node* root, int value) {
        if (!root) {
            return new Node(value);
        }
        if (value < root->key) {
            root->left = Insert(root->left, value);
        } else if (value > root->key) {
            root->right = Insert(root->right, value);
        } else {
            return root;  // Duplicate keys are not allowed
        }

        int balanceFactor = BalanceFactor(root);
        if (balanceFactor > 1) {
            if (value < root->left->key) {
                return LLrotate(root);
            } else {
                return LRrotate(root);
            }
        }
        if (balanceFactor < -1) {
            if (value > root->right->key) {
                return RRrotate(root);
            } else {
                return RLrotate(root);
            }
        }
        return root;
    }

    void IOTraversal(Node* root) {  // In-order traversal
        if (root) {
            IOTraversal(root->left);
            cout << root->key << " ";
            IOTraversal(root->right);
        }
    }

    void levelOrderTraversal(Node* root) {
        if (!root) {
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->key << " ";

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
    }
};

int main() {
    AVL mytree;

    Root = mytree.Insert(Root, 30);
    Root = mytree.Insert(Root, 5);
    Root = mytree.Insert(Root, 35);
    Root = mytree.Insert(Root, 32);
    Root = mytree.Insert(Root, 40);

    cout << "In-order traversal:" << endl;
    mytree.IOTraversal(Root);
    cout << endl;

    cout << "Level-order traversal:" << endl;
    mytree.levelOrderTraversal(Root);
    Root = mytree.Insert(Root, 45);

    cout << "In-order traversal:" << endl;
    mytree.IOTraversal(Root);
    cout << endl;

    cout << "Level-order traversal:" << endl;
    mytree.levelOrderTraversal(Root);}
