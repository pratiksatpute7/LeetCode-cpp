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
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    bool isValid(TreeNode* node, long Min, long Max){
        if(node != NULL){

            if (!(node -> val > Min && node -> val < Max)) {
                return false;
            }

            return isValid(node -> right, node -> val, Max) && 
            isValid(node -> left, Min, node -> val);
        }
        return true;
    }

};