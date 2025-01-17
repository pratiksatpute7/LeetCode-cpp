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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) {
            return true;
        }

        if(root == NULL || subRoot == NULL) {
            return false;
        }

        if(isSame(root, subRoot)) {
            return true;
        }

        return isSubtree(root -> right, subRoot) || isSubtree(root -> left, subRoot);

        
    }

    bool isSame(TreeNode* nodeRoot, TreeNode* nodeSubroot) {

        if(nodeRoot == NULL && nodeSubroot == NULL) {
            return true;
        }

        if(nodeRoot == NULL || nodeSubroot == NULL) {
            return false;
        }

        return (nodeRoot -> val == nodeSubroot -> val) && isSame(nodeRoot -> right, nodeSubroot -> right)
        && isSame(nodeRoot -> left, nodeSubroot -> left);
    }
};