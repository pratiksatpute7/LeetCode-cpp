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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> sq1;
        vector<int> sq2;
        dfs(root1, sq1);
        dfs(root2, sq2);

        if(sq1 == sq2) {
            return true;
        }

        return false;
    }

    void dfs(TreeNode* node, vector<int>& sq) {
        if(node && node -> left == nullptr && node -> right == nullptr) {
            sq.push_back(node -> val);
            return;
        }

        if(node -> left)
            dfs(node -> left, sq);
        if(node -> right)
            dfs(node -> right, sq);

    }
};