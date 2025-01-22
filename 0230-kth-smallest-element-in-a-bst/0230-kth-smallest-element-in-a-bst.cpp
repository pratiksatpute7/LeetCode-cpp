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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inOrder;
        inOrderTraversal(root, inOrder);

        return inOrder[k-1];
    }

    void inOrderTraversal(TreeNode* node, vector<int>& inOrder) {

        if(node) {
            inOrderTraversal(node -> left, inOrder);
            inOrder.push_back(node -> val);
            inOrderTraversal(node -> right, inOrder);
        }
    }
};