/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool isSymmetric(TreeNode* root) {
    //     vector<int> post;
    //     vector<int> pre;

    //     postOrder(root, post);
    //     preOrder(root, pre);

    //     reverse(post.begin(), post.end());

    //     for(int i = 0; i < post.size(); i++) {
    //         if(post[i] != pre[i]) {
    //             return false;
    //         }
    //     }

    //     return true;
    // }

    // void postOrder(TreeNode* node, vector<int>& post) {
    //     if(node == NULL) {
    //         return;
    //     }

    //     if(node -> left) {
    //         postOrder(node -> left, post);
    //     } else {
    //         post.push_back(INT_MIN);
    //     }
    //     if(node -> right) {
    //         postOrder(node -> right, post);
    //     } else {
    //         post.push_back(INT_MIN);
    //     }
    //     post.push_back(node -> val);
    // }

    // void preOrder(TreeNode* node, vector<int>& pre) {
    //     if(node == NULL) {
    //         pre.push_back(INT_MIN);
    //         return;
    //     }

    //     pre.push_back(node -> val);

    //     if(node -> left) {
    //         preOrder(node -> left, pre);
    //     } else {
    //         pre.push_back(INT_MIN);
    //     }
    //     if(node -> right) {
    //         preOrder(node -> right, pre);
    //     } else {
    //         pre.push_back(INT_MIN);
    //     }
    // }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }
};