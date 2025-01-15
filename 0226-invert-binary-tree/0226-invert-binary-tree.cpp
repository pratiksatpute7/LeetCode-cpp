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
    TreeNode* invertTree(TreeNode* root) {
        // Just apply DFS top the tree and keep swapping nodes till you reach leaf node
        if(root == NULL) {
            return root;
        }

        // swap
        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;


        // Reccursive call for DFS
        invertTree(root -> left);
        invertTree(root -> right);

        return root;

    }
};