struct Node {
    Node* links[26];
    bool end = false;

    bool checkIfCharExists(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void addChar(char ch, Node* newNode) {
        links[ch - 'a'] = newNode;
    }

    bool isEnd() {
        return end;
    }

    void setEnd() {
        end = true;
    }

    void resetEnd() {
        end = false;
    }

    Node* getLink(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
    public:
        Node* root = new Node();

        void createTrie(vector<string>& words) {
            for(string word : words) {
                Node* node = root;
                for(char ch : word) {
                    if(!node -> checkIfCharExists(ch)){
                        Node* newNode = new Node();
                        node -> addChar(ch, newNode);
                    }
                    node = node -> getLink(ch);

                }
                node -> setEnd();
            }
        }
};


class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
     void dfs(vector<string>& ans, string ds, Node* cur, int i, int j, vector<vector<char>>& board, vector<vector<bool>> &vis) {
        if (!cur)   return;


        if (cur->isEnd()){
            ans.push_back(ds);
            cur->resetEnd();
        }

        vis[i][j] = true; //marking path as visited

        for (int del = 0; del < 4; del++) {
            int next_i = i + dir[del], next_j = j + dir[del + 1];
            //checking for out of bound condition, moving to next letter
            if (next_i < board.size() and next_j < board[0].size() and !vis[next_i][next_j] and cur->checkIfCharExists(board[next_i][next_j]))
                dfs(ans, ds + board[next_i][next_j], cur->getLink(board[next_i][next_j]), next_i, next_j,board,vis);
        }
        vis[i][j]= false; //resetting the path to unvisited
     }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> vis(rows,vector<bool>(cols, false));
        vector<string> ans;

        Trie* trie = new Trie();
        trie -> createTrie(words);

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                char ch = board[row][col];
                if(trie -> root -> checkIfCharExists(ch)) {
                    dfs(ans,string(1, ch), trie -> root -> getLink(ch), row, col, board, vis);

                }
            }
        }

        return ans;
    }
};