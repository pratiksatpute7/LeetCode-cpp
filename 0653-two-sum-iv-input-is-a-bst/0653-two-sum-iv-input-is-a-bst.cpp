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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        traversal(root, inorder);
        int left = 0;
        int right = inorder.size() - 1;

        while(left < right) {
            int sum = inorder[left] + inorder[right];

            if(sum == k) {
                return true;
            }

            if(sum > k) {
                right--;
            } else {
                left++;
            }
        }

        return false;

        
    }

    void traversal(TreeNode* root, vector<int> &inorder) {
        if(root == nullptr) {
            return;
        }

        traversal(root -> left, inorder);
        inorder.push_back(root -> val);
        traversal(root -> right, inorder);
    }
};