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
private: 
    // used to iterate over the list of preorder
    int preorderIndex;
    // used to get the index value of the current preorder element 
    // so that we can call recurssive on the left and the right part 
    unordered_map<int, int> mapping;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // build mapping of inorder indexes
        for(int i = 0; i < inorder.size(); i++){
            mapping[inorder[i]] = i;
        }

        // Initilise from the first element of prorder list
        preorderIndex = 0;
        return build(preorder, 0, preorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int start, int end) {
        if(start > end){
            return NULL;
        }

        // set the current preorder value as the value of root
        int rootVal = preorder[preorderIndex];
        // increment thr index
        preorderIndex ++;
        TreeNode* root = new TreeNode(rootVal);

        // get the inorder index from the mapping
        int mid = mapping[rootVal];

        // recurssively call the left and the right to build sub trees 
        root -> left = build(preorder, start, mid - 1);
        root -> right = build(preorder, mid + 1, end);

        return root;
    }
};