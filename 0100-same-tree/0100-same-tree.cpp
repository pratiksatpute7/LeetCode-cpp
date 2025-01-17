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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
            return true;
        }
        if(p == NULL || q == NULL) {
            return false;
        }

        return (bfs(p) == bfs(q));

    }

    vector<int> bfs(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> seen;

        q.push(root);

        // Run BFS and also add nodes with null values to seen array to compare both trees 
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) {
                seen.push_back(INT_MIN);
                continue;
            }

            seen.push_back(node -> val);


            q.push(node -> left);
            q.push(node -> right);
        }

        return seen;
    }
};