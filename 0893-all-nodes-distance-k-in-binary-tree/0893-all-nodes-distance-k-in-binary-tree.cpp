/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    unordered_set<TreeNode*> visited;
    vector<int> result;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root, nullptr);
        bfs(target, k);

        return result;
    }

    void dfs(TreeNode* root, TreeNode* parent) {
        if(!root) {
            return;
        }

        mp[root] = parent;

        if(root -> left) {
            dfs(root -> left, root);
        }

        if(root -> right) {
            dfs(root -> right, root);
        }
    }

    void bfs(TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int count = 0;

        while(!q.empty()) {
            int size = q.size();

            if(count == k) {
                for(int i = 0; i < size; i++) {
                    result.push_back(q.front() -> val);
                    q.pop();
                }
                return;
            }

            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if(curr -> left && !visited.count(curr -> left)) {
                    q.push(curr -> left);
                    visited.insert(curr->left);
                }
                if(curr -> right && !visited.count(curr -> right)) {
                    q.push(curr -> right);
                    visited.insert(curr->right);
                }
                if (mp.count(curr) && mp[curr] && !visited.count(mp[curr])) {
                    q.push(mp[curr]);
                    visited.insert(mp[curr]);
                }
            }
            count++;
        }
    }
};