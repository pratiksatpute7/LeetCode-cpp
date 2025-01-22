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
    int goodNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int count = 0;
        int maxSeen = root -> val;
        getGoodNodeCount(root, maxSeen, count);

        return count;
    }

    void getGoodNodeCount(TreeNode* node, int maxSeen, int& count){
        if(node) {
            if(node -> val >= maxSeen){
                count = count + 1;
            }

            maxSeen = max(maxSeen, node -> val);

            if(node -> left){
                getGoodNodeCount(node -> left, maxSeen, count);
            }

            if(node -> right){
                getGoodNodeCount(node -> right, maxSeen, count);
            }
        }

    }
};