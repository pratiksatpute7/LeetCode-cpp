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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> view;
        // Push initial node
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node) {
                    // push only the right most available node in view
                    if(i == 0) {
                        view.push_back(node -> val);
                    }
                    //Push the right most node into the queue if availble
                    if(node -> right){
                        q.push(node -> right);
                    }


                    // push the other node in the queue to travese and if any right node is not present
                    if(node -> left){
                        q.push(node -> left);
                    }
                }
                
            }

        }

        return view;
    }
};