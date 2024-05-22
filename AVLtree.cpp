#include <iostream>
#include <queue>
#include <utility>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(): key(0), left(nullptr), right(nullptr), height(0) {}
    Node(int data): key(data), left(nullptr), right(nullptr), height(0) {}
};

Node* Root = nullptr;

class AVL {
public:
    int height(Node* root) {
        if (!root)
            return -1;
        return root->height;
    }

    int BalanceFactor(Node* root) {
        if (!root)
            return 0;
        return height(root->left) - height(root->right);
    }

    bool is_Balanced(Node *root) {
        if (!root)
            return true;
    
        int lh = height(root->left);
        int rh = height(root->right);

        return abs(lh - rh) <= 1 && is_Balanced(root->left) && is_Balanced(root->right);
    }

    Node* LLrotate(Node* root) {
        cout << "LL Rotation Performed Successfully...." << endl;
        Node* lc = root->left;
        root->left = lc->right;
        lc->right = root;

        root->height = 1 + max(height(root->left), height(root->right));
        lc->height = 1 + max(height(lc->left), height(lc->right));

        return lc;
    }

    Node* RRrotate(Node* root) {
        cout << "RR Rotation Performed Successfully...." << endl;
        Node* rc = root->right;
        root->right = rc->left;
        rc->left = root;

        root->height = 1 + max(height(root->left), height(root->right));
        rc->height = 1 + max(height(rc->left), height(rc->right));

        return rc;
    }

    Node* LRrotate(Node* root) {
        cout << "LR Rotation Performed Successfully...." << endl;
        root->left = RRrotate(root->left);
        return LLrotate(root);
    }

    Node* RLrotate(Node* root) {
        cout << "RL Rotation Performed Successfully...." << endl;
        root->right = LLrotate(root->right);
        return RRrotate(root);
    }
    
    Node* Insert(Node* root, int vl) {
        if (!root)
            return new Node(vl);

        if (vl < root->key)
            root->left = Insert(root->left, vl);
        else if (vl > root->key)
            root->right = Insert(root->right, vl);
        else
            return root; 
    
        root->height = 1 + max(height(root->left), height(root->right));
        int bf = BalanceFactor(root);

        if (bf > 1 && vl < root->left->key)
            return LLrotate(root);
        if (bf > 1 && vl > root->left->key)
            return LRrotate(root);
        if (bf < -1 && vl > root->right->key)
            return RRrotate(root);
        if (bf < -1 && vl < root->right->key)
            return RLrotate(root);

        return root;
    }

    pair<Node*, Node*> InorderSuccessor(Node* root) {
        Node* successor = root->right;
        Node* successor_prt = root;
        while (successor->left != NULL) {
            successor_prt = successor;
            successor = successor->left;
        }
        return make_pair(successor_prt, successor);
    }

    Node* delete_node(Node* root, int vl) {
        if (!root)
            return root;
    
        if (vl < root->key) {
            root->left = delete_node(root->left, vl);
        } else if (vl > root->key) {
            root->right = delete_node(root->right, vl);
        } else {
            Node* temp;
            if (root->left == NULL) {
                temp = root->right;
                delete root;
                root = temp;
            } else if (root->right == NULL) {
                temp = root->left;
                delete root;
                root = temp;
            } else {
                pair<Node*, Node*> scsr = InorderSuccessor(root);
                Node* successor_prt = scsr.first;
                Node* successor = scsr.second;
                root->key = successor->key;

                if (successor_prt->left == successor)
                    successor_prt->left = successor->right;
                else
                    successor_prt->right = successor->right;

                delete successor;
            }
        }

        if (!root)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int bf = BalanceFactor(root);

        if (bf > 1 && BalanceFactor(root->left) >= 0)
            return LLrotate(root);
        if (bf > 1 && BalanceFactor(root->left) < 0)
            return LRrotate(root);
        if (bf < -1 && BalanceFactor(root->right) <= 0)
            return RRrotate(root);
        if (bf < -1 && BalanceFactor(root->right) > 0)
            return RLrotate(root);

        return root;
    }

    void IOTraversal(Node* root) {
        if (root) {
            IOTraversal(root->left);
            printf("%d ", root->key);
            IOTraversal(root->right);
        }
    }

    void levelOrderTraversal(Node* root) {
        if (root == nullptr) 
            return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->key << " ";

            if (current->left != nullptr) 
                q.push(current->left);
            if (current->right != nullptr) 
                q.push(current->right);
        }
    }
};

int main() {
    AVL mytree;

    Root = mytree.Insert(Root, 10);
    Root = mytree.Insert(Root, 20);
    Root = mytree.Insert(Root, 30);
    Root = mytree.Insert(Root, 40);
    Root = mytree.Insert(Root, 50);

    cout << "In-order traversal:" << endl;
    mytree.IOTraversal(Root);
    cout << endl;

    cout << "Level-order traversal:" << endl;
    mytree.levelOrderTraversal(Root);
    cout << endl;

    Root = mytree.Insert(Root, 25);

    cout << "In-order traversal:" << endl;
    mytree.IOTraversal(Root);
    cout << endl;

    cout << "Level-order traversal:" << endl;
    mytree.levelOrderTraversal(Root);
    cout << endl;

    Root = mytree.delete_node(Root, 30);

    cout << "In-order traversal:" << endl;
    mytree.IOTraversal(Root);
    cout << endl;

    cout << "Level-order traversal:" << endl;
    mytree.levelOrderTraversal(Root);
    cout << endl;

    return 0;
}
