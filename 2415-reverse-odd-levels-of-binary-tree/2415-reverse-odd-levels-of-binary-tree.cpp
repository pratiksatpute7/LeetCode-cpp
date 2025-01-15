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
    TreeNode* reverseOddLevels(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        bool isOdd = false;

        while(!q.empty()) {
            vector<TreeNode*> nodes;
            vector<int> values;
            
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* current =  q.front();
                q.pop();

                nodes.push_back(current);
                values.push_back(current -> val);

                if(current-> right != NULL) {
                    q.push(current -> right);
                }
                if(current-> left != NULL) {
                    q.push(current -> left);
                }
            }

            if(isOdd) {
                // reverse the value vector and save the value to node
                reverse(values.begin(), values.end());

                for (int i = 0; i < size; i++) {
                    nodes[i]->val = values[i]; 
                }
            }

            isOdd = !isOdd;
            
        }

        return root;
        
    }
};