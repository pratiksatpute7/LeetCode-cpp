/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string tree;

        while(!q.empty()){

            TreeNode* node = q.front();
            q.pop();
            if(node) {
                tree += to_string(node->val) + ",";
                q.push(node -> left);
                q.push(node -> right);
            } else {
                tree += "#,";
            }
        }

        // cout << tree;
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data == "#,") return nullptr; // Handle edge case for empty tree

        // Split the serialized string into nodes
        queue<string> nodes;
        stringstream ss(data);
        string item;

        while (getline(ss, item, ',')) {
            nodes.push(item);
        }

        // Extract the root node
        string rootVal = nodes.front();
        nodes.pop();
        TreeNode* root = new TreeNode(stoi(rootVal)); // Create the root node

        // Use a queue to reconstruct the tree
        queue<TreeNode*> q;
        q.push(root);

        while (!nodes.empty()) {
            TreeNode* parent = q.front();
            q.pop();

            // Process the left child
            string leftVal = nodes.front();
            nodes.pop();
            if (leftVal != "#") {
                parent->left = new TreeNode(stoi(leftVal));
                q.push(parent->left);
            }

            // Process the right child
            if (!nodes.empty()) {
                string rightVal = nodes.front();
                nodes.pop();
                if (rightVal != "#") {
                    parent->right = new TreeNode(stoi(rightVal));
                    q.push(parent->right);
                }
            }
        }

        return root;

        }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));