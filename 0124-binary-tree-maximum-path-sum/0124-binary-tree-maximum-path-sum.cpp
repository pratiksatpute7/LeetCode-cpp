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
    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        sum(root, maxValue);

        return maxValue;
        
    }

    int sum(TreeNode* node, int& maxValue) {

        if(node == NULL){
            return 0;
        }

        int leftVal = max(0, sum(node -> left, maxValue));
        int rightVal = max(0, sum(node -> right, maxValue));

        int sum = leftVal + rightVal + node -> val;

        maxValue = max(sum, maxValue);   

        return max(leftVal + node -> val, rightVal + node -> val);
    }
    // int sum(TreeNode* node, int& maxValue) {

    //     if(node == NULL){
    //         return 0;
    //     }

    //     int leftVal = max(0, sum(node -> left, maxValue));
    //     int rightVal = max(0, sum(node -> right, maxValue));

    //     int sum = leftVal + rightVal + node -> val;

    //     maxValue = max(max(max(max(leftVal + node -> val, rightVal + node -> val), node -> val), sum), maxValue);   

    //     return max(leftVal + node -> val, rightVal + node -> val);
    // }
};

