/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || (root -> left == NULL && root -> right == NULL)) {
            return root;
        }

        if(root -> left != NULL && root -> right != NULL) {
            root -> left -> next = root -> right;
            root -> right -> next = GetNextForChilderenUsingRoot(root);
        }

        if(root -> left == NULL) {
            root -> right -> next = GetNextForChilderenUsingRoot(root);
        }

        if(root -> right == NULL) {
            root -> left -> next = GetNextForChilderenUsingRoot(root);
        }

        root -> right = connect(root -> right);
        root -> left = connect(root -> left);

        return root;

    }

    Node* GetNextForChilderenUsingRoot(Node* root) {
        while(root -> next != NULL){
            if(root -> next -> left != NULL){
                return root -> next -> left;
            }

            if(root -> next -> right != NULL) {
                return root -> next -> right;
            }

            root = root -> next;

        }

        return NULL;
    }
};