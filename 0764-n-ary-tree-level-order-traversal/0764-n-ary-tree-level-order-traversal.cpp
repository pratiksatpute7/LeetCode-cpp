/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> level;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return level;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            
            vector<int> levelChildern;
            for(int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                levelChildern.push_back(curr -> val);

                for(Node* child: curr -> children) {
                    q.push(child);
                }
            }
            level.push_back(levelChildern);
        }

        return level;
    }
};