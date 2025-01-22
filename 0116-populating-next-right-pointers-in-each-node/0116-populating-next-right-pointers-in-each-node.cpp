/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        queue<Node*> q;
        q.push(root);
        vector<char> result;

        while(!q.empty()){
            int size = q.size();

            //Run the for loop for each level
            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();

                // if last node in the q then set next - > null
                if(node) {
                    if(i == size - 1){
                        node -> next = NULL;
                    } else {
                        // else just set the current -> next to the node at the front of the queue
                        node -> next = q.front();
                    }

                    if(node -> left) {
                        q.push(node -> left);
                    }

                    if(node -> right) {
                        q.push(node -> right);
                    }
                }
            }
        }
        return root;
    }
};