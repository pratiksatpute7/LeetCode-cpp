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
    bool isBalanced(TreeNode* root) {
      return check(root) != -1;
    }

    int check(TreeNode* node) {
        if(node == NULL) {
            return 0;
        }

        int leftHeight = check(node -> left);
        if(leftHeight == -1) {
            return -1;
        }

        int rightHeight = check(node -> right);
        if(rightHeight == -1) {
            return -1;
        }

        if(abs(rightHeight - leftHeight) > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }
};