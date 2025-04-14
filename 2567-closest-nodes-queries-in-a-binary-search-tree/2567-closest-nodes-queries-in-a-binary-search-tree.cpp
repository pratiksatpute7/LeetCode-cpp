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
    vector<int> inorder;
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);
        vector<vector<int>> answer;
        for(int num : queries) {
            int max = binarySearchMax(num);
            int min = binarySearchMin(num);
            // vector<int> output = {min <= num ? min : -1, max >= num ? max : -1};
            answer.push_back({min, max});

        }
        return answer;
    }

    void dfs(TreeNode* root){
        if(!root) {
            return;
        }
        dfs(root -> left);
        inorder.push_back(root -> val);
        dfs(root -> right);

    }

    int binarySearchMax(int target) {
        int start = 0;
        int end = inorder.size() - 1;
        int ans = -1;
        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(inorder[mid] >= target) {
                ans = inorder[mid];
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    int binarySearchMin(int target) {
        int start = 0;
        int end = inorder.size() - 1;
        int ans = -1;

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(inorder[mid] <= target) {
                ans = inorder[mid];
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};